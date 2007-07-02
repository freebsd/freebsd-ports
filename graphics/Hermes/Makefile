# New ports collection makefile for:	Hermes
# Date created:				29 April 1999
# Whom:					Andrey Zakhvatov
#
# $FreeBSD$
#

PORTNAME=	Hermes
PORTVERSION=	1.3.3
PORTREVISION=	2
CATEGORIES=	graphics
MASTER_SITES=	ftp://ftp.su.se/pub/lunar/source-archive/ \
		${MASTER_SITE_GENTOO}
MASTER_SITE_SUBDIR=	distfiles

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Fast pixel formats conversion library

USE_AUTOTOOLS=	libtool:15
USE_BZIP2=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
MAKE_ARGS=	ACLOCAL="${TRUE}" AUTOCONF="${TRUE}" AUTOMAKE="${TRUE}" \
		AUTOHEADER="${TRUE}"
USE_LDCONFIG=	yes

PORTDOCS=	*

.include <bsd.port.pre.mk>

.if ${ARCH} == sparc64
IGNORE=		is broken on sparc64: interchanges red and blue colour channels in images
.endif

.if ${ARCH} == i386 && ${OSVERSION} >= 700042
BROKEN=		Does not compile with GCC 4.2 on i386
.endif

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for file in AUTHORS ChangeLog FAQ README TODO TODO.conversion
	${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
	@${MKDIR} ${DOCSDIR}/API
.for f in api-1.htm api-2.htm api-3.htm api-4.htm api.htm api.ps api.txt
	${INSTALL_DATA} ${WRKSRC}/docs/api/${f} ${DOCSDIR}/API
.endfor
	${INSTALL_DATA} ${WRKSRC}/docs/api/sgml/api.sgml ${DOCSDIR}/API
.endif

.include <bsd.port.post.mk>
