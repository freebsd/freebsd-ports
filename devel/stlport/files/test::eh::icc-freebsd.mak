# This requires GNU make.

srcdir = .
VPATH = .
SHELL=/bin/sh

# point this to proper location
STL_INCL=-I../../stlport

AUX_LIST=TestClass.cpp main.cpp nc_alloc.cpp random_number.cpp

TEST_LIST=test_algo.cpp  \
test_algobase.cpp     test_list.cpp test_slist.cpp \
test_bit_vector.cpp   test_vector.cpp \
test_deque.cpp test_set.cpp test_map.cpp \
test_hash_map.cpp  test_hash_set.cpp test_rope.cpp \
test_string.cpp test_bitset.cpp test_valarray.cpp

LIST=$(AUX_LIST) $(TEST_LIST)

OBJECTS = $(LIST:%.cpp=obj/%.o) $(STAT_MODULE)
D_OBJECTS = $(LIST:%.cpp=d_obj/%.o) $(STAT_MODULE)

EXECS = $(LIST:%.cpp=%)
TESTS = $(LIST:%.cpp=%.out)
TEST_EXE  = ./eh_test
D_TEST_EXE = ./eh_test_d

TEST  = ./eh_test.out
D_TEST = ./eh_test_d.out

CXXFLAGS += $(PTHREAD_CFLAGS) -D_REENTRANT -w1 $(STL_INCL) -I. $(CXX_EXTRA_FLAGS) -DEH_VECTOR_OPERATOR_NEW -DEH_DELETE_HAS_THROW_SPEC
D_CXXFLAGS = $(CXXFLAGS) -g -D_STLP_DEBUG

check: $(TEST)

LIBS = -lm -mt
D_LIBSTLPORT = -L../../lib -lstlport_icc_stldebug
LIBSTLPORT = -L../../lib -lstlport_icc

all: $(TEST_EXE) $(D_TEST_EXE)

check_d: $(D_TEST)

OBJDIR=obj
D_OBJDIR=d_obj

$(OBJDIR):
	mkdir obj
$(D_OBJDIR):
	mkdir d_obj


$(TEST_EXE) : $(OBJDIR) $(OBJECTS)
	$(CC) $(CXXFLAGS) $(OBJECTS) $(LIBSTLPORT) $(LIBS) -o $(TEST_EXE)

$(D_TEST_EXE) : $(D_OBJDIR) $(D_OBJECTS)
	$(CC) $(D_CXXFLAGS) $(D_OBJECTS) $(D_LIBSTLPORT) $(LIBS) -o $(D_TEST_EXE)


$(TEST) : $(TEST_EXE)
	LD_LIBRARY_PATH="../../lib:$(LD_LIBRARY_PATH)" ./$(TEST_EXE) -s 100

$(D_TEST) : $(D_TEST_EXE)
	LD_LIBRARY_PATH="../../lib:$(LD_LIBRARY_PATH)" ./$(D_TEST_EXE) -s 100

SUFFIXES: .cpp.o

d_obj/%.o : %.cpp
	$(CXX) $(D_CXXFLAGS) $< -c -o $@

obj/%.o : %.cpp
	$(CXX) $(CXXFLAGS) $< -c -o $@

clean:
	-rm -rf $(TEST_EXE) *.o */*.o *.core
