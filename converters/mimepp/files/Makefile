# UNIX makefile for MIME++ example programs

# $Revision: 3.0 $
# $Date: 1997-07-28 06:59:15-05 $

# C++ compiler driver
# CXX = CC
CXX = g++

# C++ compiler flags (except -c, -I, -L, -l)
#
# Add -g here if you want debugger symbols included
CXXFLAGS = -O

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

all: exampl01 exampl02 exampl03 exampl04 exampl05

exampl01 : libmimepp.a exampl01.o basicmsg.o
	$(CXX) -o exampl01 exampl01.o basicmsg.o $(LIB_PATH) -lmimepp $(LIBS)

exampl02 : libmimepp.a exampl02.o basicmsg.o
	$(CXX) -o exampl02 exampl02.o basicmsg.o $(LIB_PATH) -lmimepp $(LIBS)

exampl03 : libmimepp.a exampl03.o multipar.o basicmsg.o
	$(CXX) -o exampl03 exampl03.o multipar.o basicmsg.o $(LIB_PATH) -lmimepp $(LIBS)

exampl04 : libmimepp.a exampl04.o multipar.o basicmsg.o
	$(CXX) -o exampl04 exampl04.o multipar.o basicmsg.o $(LIB_PATH) -lmimepp $(LIBS)

exampl05 : libmimepp.a exampl05.o attach.o multipar.o basicmsg.o
	$(CXX) -o exampl05 exampl05.o attach.o multipar.o basicmsg.o $(LIB_PATH) -lmimepp $(LIBS)

clean:
	-rm *.o exampl0? *.out

.SUFFIXES: .cpp

.cpp.o:
	$(CXX) -c $(CXXFLAGS) $< $(INC_PATH)
