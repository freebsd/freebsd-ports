# New ports collection makefile for:	joe-devel
# Date created:		25 Jul 2001
# Whom:			dwcjr@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	joe
PORTVERSION=	3.0
PORTEPOCH=	1
CATEGORIES=	editors
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	joe-editor
PKGNAMESUFFIX=	-devel
DISTNAME=	joe-${PORTVERSION}

MAINTAINER=	petef@FreeBSD.org
COMMENT=	Development version of Joe's own editor

CONFLICTS=	joe-2.*
LATEST_LINK=	joe-devel

GNU_CONFIGURE=	yes
CONFIGURE_TARGET=--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib -liconv"

USE_GMAKE=	yes
USE_ICONV=	yes
USE_REINPLACE=	yes

ALL_TARGET=	joe
MAN1=		joe.1

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
post-patch:
	@${REINPLACE_CMD} -e 's/towupper/__toupper/g' ${WRKSRC}/regex.c
	@${REINPLACE_CMD} -e 's/iswalnum(c)/__istype(c, _CTYPE_A|_CTYPE_D)/' ${WRKSRC}/utils.c
.endif

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/INFO ${WRKSRC}/README ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/LIST ${DOCSDIR}/CommandList
.endif
.for file in jmacsrc jpicorc jstarrc rjoerc joerc
.if !exists(${PREFIX}/etc/joe/${file})
	@${CP} ${PREFIX}/etc/joe/${file} ${PREFIX}/etc/joe/${file}.dist
.endif
.endfor

.include <bsd.port.post.mk>
