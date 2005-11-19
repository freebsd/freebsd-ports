# New ports collection makefile for:	libbegemot
# Date created:			Sep 15 2005
# Whom:				Andrey V. Elsukov <bu7cher@yandex.ru>
#
# $FreeBSD$
#

PORTNAME=	libbegemot
PORTVERSION=	1.11
CATEGORIES=	devel
MASTER_SITES=	http://people.freebsd.org/~harti/libbegemot/
DISTNAME=	libbegemot-${PORTVERSION}

MAINTAINER=	bu7cher@yandex.ru
COMMENT=	A function library for begemot tools

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_AUTOTOOLS=	automake:19:env autoconf:259:env libltdl:15 libtool:15:env
INSTALLS_SHLIB=	yes


MAN1=	cstrc.1 frame.1 getfields.1 intro.1 panic.1 prstat.1 readline.1 \
		rpoll.1 strnchr.1 strnlen.1 strsave.1 strtrimsp.1 verb.1 xalloc.1
MLINKS=	xalloc.1 xrealloc.1

run-autotools::
	@(cd ${CONFIGURE_WRKSRC} && ${ACLOCAL} -I ${LIBTOOL_SHAREDIR}/libltdl/)
	@(cd ${CONFIGURE_WRKSRC} && ${AUTOCONF})

post-install:
.for i in ${MAN1}
	@${CP} ${WRKSRC}/${i:S/.1/.man/} ${WRKSRC}/${i}
	${INSTALL_MAN} ${WRKSRC}/${i} ${MANPREFIX}/man/man1
.endfor

.include <bsd.port.mk>
