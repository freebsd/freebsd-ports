# Ports collection Makefile for:	Hesiod
# Version required:			3.0.2
# Date created:				6/11/1998
# Whom:					n@nectar.com
#
# $FreeBSD$
#

DISTNAME=		hesiod-3.0.2
CATEGORIES=		net
MASTER_SITES=		ftp://athena-dist.mit.edu/pub/ATHENA/hesiod/   \
			http://www.nectar.cc/distfiles/

MAINTAINER=		nectar@FreeBSD.org

MAN1=			hesinfo.1
MAN3=			hesiod.3 hesiod_end.3 hesiod_free_list.3 	\
			hesiod_free_passwd.3 hesiod_free_postoffice.3 	\
			hesiod_free_servent.3 hesiod_getmailhost.3 	\
			hesiod_getpwnam.3 hesiod_getpwuid.3 		\
			hesiod_getservbyname.3 hesiod_init.3 		\
			hesiod_resolve.3 hesiod_to_bind.3
MAN5=			hesiod.conf.5

GNU_CONFIGURE=		YES

.include <bsd.port.pre.mk>

.if ${PORTOBJFORMAT} == elf
VERSION=3
SONAME="-Wl,-soname,libhesiod.so.${VERSION}"
.else
VERSION=3.0
.endif

MAKE_ENV+=		VERSION="${VERSION}" SONAME="${SONAME}"

post-install:
	${SETENV} OBJFORMAT="${PORTOBJFORMAT}" ${LDCONFIG} -m ${PREFIX}/lib

.include <bsd.port.post.mk>
