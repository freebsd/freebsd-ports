# ex:ts=8
# New ports collection makefile for:	libFormat
# Date created:			Jun 19, 2001
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	libformat
PORTVERSION=	0.1.7
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	http://home.pages.at/kingleo/development/
DISTNAME=	Format-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org

USE_REINPLACE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${ARCH}-portbld-freebsd${OSREL}
INSTALLS_SHLIB=	yes

MAN3=	Format.3

post-patch:
	@${REINPLACE_CMD} -e 's| install-data-local||g' ${WRKSRC}/doc/Makefile.in

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for file in doc/Format.html doc/Format.txt src/testMakefile src/testformat.cpp
	${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
