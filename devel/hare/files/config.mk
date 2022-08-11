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
BINOUT = .bin

# Cross-compiler toolchains
AARCH64_AS=aarch64-as
AARCH64_AR=aarch64-ar
AARCH64_CC=aarch64-cc
AARCH64_LD=aarch64-ld

RISCV64_AS=riscv64-as
RISCV64_AR=riscv64-ar
RISCV64_CC=riscv64-cc
RISCV64_LD=riscv64-ld

X86_64_AS=as
X86_64_AR=ar
X86_64_CC=cc
X86_64_LD=ld
