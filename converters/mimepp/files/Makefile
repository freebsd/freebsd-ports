# makefile for MIME++ example programs

# C++ compiler driver
CXX = g++

# C++ compiler flags (except -c, -I, -L, -l)
# Add -g here if you want debugger symbols included
CXXFLAGS = -DDW_EOL_LF

# The search path for include files. Change only if necessary.
INC_PATH = -I/usr/local/include

# The search path for library files. Change only if necessary.
LIB_PATH = -L/usr/local/lib

# Libraries to be included. Change only if necessary.
LIBS =

# The library directory where MIME++ (libmimepp.a) will be installed.
LIB_DIR = /usr/local/lib

# The include directory where MIME++ include files should be installed.
# The include files will actually be copied to $(INC_DIR)/mimepp/.
INC_DIR = /usr/local/include

LIB_OBJ = $(LIB_CC:.cc=.o)

all: exampl01 exampl02 exampl03 exampl04 exampl05

exampl01 : exampl01.o basicmsg.o libmimepp.a
	$(CXX) -o exampl01 exampl01.o basicmsg.o $(LIB_PATH) -lmimepp

exampl02 : exampl02.o basicmsg.o libmimepp.a
	$(CXX) -o exampl02 exampl02.o basicmsg.o $(LIB_PATH) -lmimepp

exampl03 : exampl03.o multipar.o basicmsg.o libmimepp.a
	$(CXX) -o exampl03 exampl03.o multipar.o basicmsg.o $(LIB_PATH) -lmimepp

exampl04 : exampl04.o multipar.o basicmsg.o libmimepp.a
	$(CXX) -o exampl04 exampl04.o multipar.o basicmsg.o $(LIB_PATH) -lmimepp

exampl05 : exampl05.o attach.o multipar.o basicmsg.o libmimepp.a
	$(CXX) -o exampl05 exampl05.o attach.o multipar.o basicmsg.o $(LIB_PATH) -lmimepp

clean:
	-rm *.o exampl0? *.out

.SUFFIXES: .cc

.cc.o:
	$(CXX) -c $(CXXFLAGS) $< $(INC_PATH)
