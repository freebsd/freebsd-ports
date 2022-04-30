## Install configuration

#PREFIX = /usr
BINDIR = $(PREFIX)/bin
MANDIR = $(PREFIX)/man
DATADIR= $(PREFIX)/share/hare
SRCDIR = $(DATADIR)/src

# Where to install the stdlib tree
STDLIB = $(SRCDIR}/stdlib

# Default HAREPATH
LOCALSRCDIR = ${SRCDIR}/local-src
HAREPATH = $(LOCALSRCDIR)/stdlib:$(LOCALSRCDIR)/third-party:$(DATADIR)/stdlib:$(DATADIR)/third-party

## Build configuration

# Platform to build for
PLATFORM = freebsd
#ARCH = x86_64

# External tools and flags
HAREC = harec
HAREFLAGS =
QBE = qbe
AS = as
LD = ld
AR = ar
SCDOC = scdoc

# Where to store build artifacts
HARECACHE = .cache
