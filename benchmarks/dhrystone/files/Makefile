OBJS= dhry_1.o dhry_2.o

all: dhry

dhry: $(OBJS)
	$(CC) $(LDFLAGS) -o $@ $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -o $@ $<
