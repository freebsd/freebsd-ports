# New ports collection makefile for:	Hermes
# Date created:				29 April 1999
# Whom:					Andrey Zakhvatov
#
# $FreeBSD$
#

PORTNAME=	Hermes
PORTVERSION=	1.3.3
PORTREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	http://www.clanlib.org/download/files/ \
		http://distro.ibiblio.org/pub/linux/distributions/sorcerer/sources/Hermes/1.3.3/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Fast pixel formats conversion library

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_INC_LIBTOOL_VER=13
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
MAKE_ARGS=	ACLOCAL="${TRUE}" AUTOCONF="${TRUE}" AUTOMAKE="${TRUE}" \
		AUTOHEADER="${TRUE}"
INSTALLS_SHLIB=	yes

.include <bsd.port.pre.mk>

.if ${ARCH} == sparc64
IGNORE=		"is broken on sparc64: interchanges red and blue colour channels in images"
.endif

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for file in AUTHORS ChangeLog FAQ README TODO TODO.conversion
	${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
	@${MKDIR} ${DOCSDIR}/API
.for file in api-1.htm api-2.htm api-3.htm api-4.htm api.htm api.ps api.txt
	${INSTALL_DATA} ${WRKSRC}/docs/api/${file} ${DOCSDIR}/API
.endfor
	${INSTALL_DATA} ${WRKSRC}/docs/api/sgml/api.sgml ${DOCSDIR}/API
.endif

.include <bsd.port.post.mk>
