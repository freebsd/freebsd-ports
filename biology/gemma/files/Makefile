
GEMMA_VERSION = $(shell cat ./VERSION)
VGEN		= scripts/gen_version_info.sh
CXXFLAGS	+= -DHAVE_INLINE -Wall -std=gnu++11
CXXFLAGS 	+= -DNDEBUG -Icontrib/catch-1.9.7 -Isrc

SRC_DIR		= ./src
TEST_SRC_DIR	= ./test/src
DESTDIR		?= .
PREFIX		?= /usr/local
MKDIR		?= mkdir
INSTALL		?= install

BIN		= gemma
HDR		= $(wildcard src/*.h) ./src/version.h
SOURCES		= $(wildcard src/*.cpp)
OBJS		= $(SOURCES:.cpp=.o)
LDFLAGS		+= -lgsl -lz

.PHONY: all test

all: $(BIN)

./src/version.h: ./VERSION
	$(shell bash $(VGEN) $(GUIX_PROFILE) > src/version.h)

$(BIN): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(BIN) $(OBJS) $(LDFLAGS)

$(OBJS): $(HDR)

install: all
	$(MKDIR) -p $(DESTDIR)$(PREFIX)/bin
	$(INSTALL) -s -c $(BIN) $(DESTDIR)$(PREFIX)/bin

.SUFFIXES : .cpp .c .o $(SUFFIXES)

./bin/unittests-gemma: contrib/catch-1.9.7/catch.hpp $(TEST_SRC_DIR)/unittests-main.o $(TEST_SRC_DIR)/unittests-math.o $(OBJS)
	$(CXX) $(CXXFLAGS) $(TEST_SRC_DIR)/unittests-main.o  $(TEST_SRC_DIR)/unittests-math.o $(filter-out src/main.o, $(OBJS)) $(LIBS) -o ./bin/unittests-gemma

unittests: all ./bin/unittests-gemma
	./bin/unittests-gemma

fast-check: all unittests
	rm -vf test/output/*
	cd test && ./dev_test_suite.sh | tee ../dev_test.log
	grep -q 'success rate: 100%' dev_test.log

slow-check: all
	rm -vf test/output/*
	cd test && ./test_suite.sh | tee ../test.log
	grep -q 'success rate: 100%' test.log

lengthy-check: all
	rm -vf test/output/*
	cd test && ./lengthy_test_suite.sh | tee ../lengthy_test.log
	grep -q 'success rate: 100%' lengthy_test.log

check: fast-check slow-check

check-all: check lengthy-check

clean:
	rm -vf $(SRC_DIR)/*.o
	rm -vf $(SRC_DIR)/*~
	rm -vf $(TEST_SRC_DIR)/*.o
	rm -vf $(BIN)
	rm -vf ./bin/unittests-gemma
