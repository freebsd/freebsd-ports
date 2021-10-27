all: HellmanAttacks

OBJ = aes.o bits.o calculate_bucket.o cxxopts.o encoding.o hellman.o picosha2.o plotter_disk.o pos_constants.o prover_disk.o sort_on_disk.o util.o verifier.o

.SUFFIXES:.hpp .o

.hpp.o:
	$(CC) -c $(CXXFLAGS) $(DFLAGS) $(INCLUDES) $< -o $@

HellmanAttacks: ${OBJ}
	${CC} -o HellmanAttacks ${OBJ}

clean:
	rm -f HellmanAttacks ${OBJ}
