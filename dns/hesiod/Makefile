# Ports collection Makefile for:	Hesiod
# Date created:				6/11/1998
# Whom:					n@nectar.com
#
# $FreeBSD$
#

PORTNAME=		hesiod
PORTVERSION=		3.0.2
CATEGORIES=		dns
MASTER_SITES=		ftp://athena-dist.mit.edu/pub/ATHENA/hesiod/

MAINTAINER=		nectar@FreeBSD.org
COMMENT=		A directory service built on DNS and BIND

MAN1=			hesinfo.1
MAN3=			hesiod.3 hesiod_end.3 hesiod_free_list.3 	\
			hesiod_free_passwd.3 hesiod_free_postoffice.3 	\
			hesiod_free_servent.3 hesiod_getmailhost.3 	\
			hesiod_getpwnam.3 hesiod_getpwuid.3 		\
			hesiod_getservbyname.3 hesiod_init.3 		\
			hesiod_resolve.3 hesiod_to_bind.3
MAN5=			hesiod.conf.5

GNU_CONFIGURE=		yes
INSTALLS_SHLIB=		yes

.include <bsd.port.pre.mk>

.if ${PORTOBJFORMAT} == elf
VERSION=3
SONAME="-Wl,-soname,libhesiod.so.${VERSION}"
.else
VERSION=3.0
.endif

MAKE_ENV+=		VERSION="${VERSION}" SONAME="${SONAME}"
CFLAGS+=	-fPIC

.include <bsd.port.post.mk>
