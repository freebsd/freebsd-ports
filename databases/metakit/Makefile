# New ports collection makefile for:	metakit
# Date created:		25 December 1999
# Whom:			Russell L. Carter <rcarter@pinyon.org>
#
# $FreeBSD$
#

PORTNAME=	metakit
PORTVERSION=	2.01
CATEGORIES=	databases python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	rcarter@pinyon.org

BUILD_DEPENDS=	python1.5:${PORTSDIR}/lang/python15
RUN_DEPENDS=	python1.5:${PORTSDIR}/lang/python15

WRKSRC=		${WRKDIR}/${DISTNAME}/builds

USE_LIBTOOL=	yes
CONFIGURE_SCRIPT=	../unix/configure
LIBTOOLFILES=	${CONFIGURE_SCRIPT}
INSTALLS_SHLIB=	yes

CONFIGURE_ARGS=	--enable-python
MAKE_ARGS=	CXXFLAGS="-Dq4_STD ${CFLAGS} -fpermissive"
ALL_TARGET=	all Mk4py.so

post-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/Mk4py.so ${PREFIX}/lib/python1.5/site-packages
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/metakit
	(cd ${WRKSRC}/../doc && ${TAR} -c -f - .) \
		| (cd ${PREFIX}/share/doc/metakit && ${TAR} --unlink -x -f -)
.endif

.include <bsd.port.mk>
