# Ports collection Makefile for:	Hesiod
# Version required:			3.0.2
# Date created:				6/11/1998
# Whom:					n@nectar.com
#
# $Id: Makefile,v 1.2 1998/07/05 13:09:46 asami Exp $
#

DISTNAME=		hesiod-3.0.2
CATEGORIES=		net
MASTER_SITES=		ftp://athena-dist.mit.edu/pub/ATHENA/hesiod/

MAINTAINER=		nectar@FreeBSD.ORG

MAN1=			hesinfo.1
MAN3=			hesiod.3 hesiod_end.3 hesiod_free_list.3 	\
			hesiod_free_passwd.3 hesiod_free_postoffice.3 	\
			hesiod_free_servent.3 hesiod_getmailhost.3 	\
			hesiod_getpwnam.3 hesiod_getpwuid.3 		\
			hesiod_getservbyname.3 hesiod_init.3 		\
			hesiod_resolve.3 hesiod_to_bind.3
MAN5=			hesiod.conf.5

GNU_CONFIGURE=		YES

post-install:
	${SETENV} OBJFORMAT="${PORTOBJFORMAT}" ${LDCONFIG} -m ${PREFIX}/lib

.include <bsd.port.mk>

.if !defined(PORTOBJFORMAT) # bsd.port.mk must be out of date
PORTOBJFORMAT=		aout
CONFIGURE_ENV+=		PORTOBJFORMAT="${PORTOBJFORMAT}"
MAKE_ENV+=		PORTOBJFORMAT="${PORTOBJFORMAT}"
.endif

.if ${PORTOBJFORMAT} == elf
SHLIB=libhesiod.so.3
CONFIGURE_ENV+=		LDFLAGS="-shared -Wl,-soname,${SHLIB}"
.else
SHLIB=libhesiod.so.3.0
CONFIGURE_ENV+=		LDFLAGS="-shared"
.endif

MAKE_ENV+=		SHLIB="${SHLIB}"
