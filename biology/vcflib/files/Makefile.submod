#OBJ_DIR = ./
HEADERS = src/Variant.h \
		  src/split.h \
		  src/join.h
SOURCES = src/Variant.cpp \
		  src/split.cpp
OBJECTS= $(SOURCES:.cpp=.o)

VCF_LIB_LOCAL:=$(shell pwd)
BIN_DIR:=bin
LIB_DIR:=lib
SRC_DIR=src
INC_DIR:=include
OBJ_DIR:=obj

include Makefile.common

TABIX = tabixpp/tabix.o
FASTAHACK = fastahack/Fasta.o
SMITHWATERMAN = smithwaterman/SmithWatermanGotoh.o
REPEATS = smithwaterman/Repeats.o
INDELALLELE = smithwaterman/IndelAllele.o
DISORDER = smithwaterman/disorder.o
LEFTALIGN = smithwaterman/LeftAlign.o
FSOM = fsom/fsom.o
FILEVERCMP = filevercmp/filevercmp.o

INCLUDES = -Itabixpp/htslib -I$(INC_DIR) -L. -Ltabixpp/htslib
LDFLAGS = -L$(LIB_DIR) -lvcflib -lhts -lpthread -lz -lm


all: $(OBJECTS) $(BINS)

CXX ?= c++
CXXFLAGS ?= -O3 -D_FILE_OFFSET_BITS=64
#CXXFLAGS = -O2
#CXXFLAGS = -pedantic -Wall -Wshadow -Wpointer-arith -Wcast-qual

SSW = src/ssw.o src/ssw_cpp.o

ssw.o: src/ssw.h
ssw_cpp.o:src/ssw_cpp.h

openmp:
	$(MAKE) CXXFLAGS="$(CXXFLAGS) -fopenmp -D HAS_OPENMP"

profiling:
	$(MAKE) CXXFLAGS="$(CXXFLAGS) -g" all

gprof:
	$(MAKE) CXXFLAGS="$(CXXFLAGS) -pg" all

$(OBJECTS): $(SOURCES) $(HEADERS) $(TABIX) multichoose pre $(SMITHWATERMAN) $(FILEVERCMP)
	$(CXX) -c -o $@ src/$(*F).cpp $(INCLUDES) $(LDFLAGS) $(CXXFLAGS) && cp src/*.h* $(VCF_LIB_LOCAL)/$(INC_DIR)/

multichoose: pre
	cd multichoose && $(MAKE) && cp *.h* $(VCF_LIB_LOCAL)/$(INC_DIR)/

intervaltree: pre
	cd intervaltree && $(MAKE) && cp *.h* $(VCF_LIB_LOCAL)/$(INC_DIR)/

$(TABIX): pre
	cd tabixpp && $(MAKE) && cp *.h* $(VCF_LIB_LOCAL)/$(INC_DIR)/

$(SMITHWATERMAN): pre
	cd smithwaterman && $(MAKE) && cp *.h* $(VCF_LIB_LOCAL)/$(INC_DIR)/ && cp *.o $(VCF_LIB_LOCAL)/$(OBJ_DIR)/

$(DISORDER): $(SMITHWATERMAN)

$(REPEATS): $(SMITHWATERMAN)

$(LEFTALIGN): $(SMITHWATERMAN)

$(INDELALLELE): $(SMITHWATERMAN)

$(FASTAHACK): pre
	cd fastahack && $(MAKE) && cp *.h* $(VCF_LIB_LOCAL)/$(INC_DIR)/ && cp Fasta.o $(VCF_LIB_LOCAL)/$(OBJ_DIR)/

#$(FSOM):
#	cd fsom && $(CXX) $(CXXFLAGS) -c fsom.c -lm

$(FILEVERCMP): pre
	cd filevercmp && make && cp *.h* $(VCF_LIB_LOCAL)/$(INC_DIR)/ && cp *.o $(VCF_LIB_LOCAL)/$(INC_DIR)/

$(SHORTBINS): pre
	$(MAKE) bin/$@

$(BINS): $(BIN_SOURCES) libvcflib.a $(OBJECTS) $(SMITHWATERMAN) $(FASTAHACK) $(DISORDER) $(LEFTALIGN) $(INDELALLELE) $(SSW) $(FILEVERCMP) pre intervaltree
	$(CXX) src/$(notdir $@).cpp -o $@ $(INCLUDES) $(LDFLAGS) $(CXXFLAGS)

libvcflib.a: $(OBJECTS) $(SMITHWATERMAN) $(REPEATS) $(FASTAHACK) $(DISORDER) $(LEFTALIGN) $(INDELALLELE) $(SSW) $(FILEVERCMP) $(TABIX) pre
	ar rs libvcflib.a $(OBJECTS) smithwaterman/sw.o $(FASTAHACK) $(SSW) $(FILEVERCMP) $(TABIX)
	cp libvcflib.a $(LIB_DIR)


test: $(BINS)
	@prove -Itests/lib -w tests/*.t

pre:
	if [ ! -d $(BIN_DIR) ]; then mkdir -p $(BIN_DIR); fi
	if [ ! -d $(LIB_DIR) ]; then mkdir -p $(LIB_DIR); fi
	if [ ! -d $(INC_DIR) ]; then mkdir -p $(INC_DIR); fi
	if [ ! -d $(OBJ_DIR) ]; then mkdir -p $(OBJ_DIR); fi

clean:
	rm -f $(BINS) $(OBJECTS)
	rm -f ssw_cpp.o ssw.o
	rm -f libvcflib.a
	rm -rf $(BIN_DIR)
	rm -rf $(LIB_DIR)
	rm -rf $(INC_DIR)
	rm -rf $(OBJ_DIR)
	cd tabixpp && make clean
	cd smithwaterman && make clean
	cd fastahack && make clean

.PHONY: clean all test pre
