# New ports collection makefile for:	TEA
# Date created:			13 Jul 2004
# Whom:				Jean-Yves Lefort <jylefort@brutele.be>
#
# $FreeBSD$
#

PORTNAME=		tea
PORTVERSION=		0.9.1
CATEGORIES=		editors
MASTER_SITES=		http://tea.linux.kiev.ua/
DISTNAME=		${PORTNAME}

MAINTAINER=		jylefort@brutele.be
COMMENT=		A simple GTK+ text editor

WRKSRC=			${WRKDIR}/${PORTNAME}-${PORTVERSION}

USE_X_PREFIX=		yes
USE_BZIP2=		yes
GNU_CONFIGURE=		yes
USE_GCC=		3.3
USE_GNOME=		gtk20
CONFIGURE_ENV=		CPPFLAGS="-I${LOCALBASE}/include" \
			LDFLAGS="-L${LOCALBASE}/lib"

.if !defined(NOPORTDOCS)
post-install:
	${MKDIR} ${DOCSDIR}/en
	${MKDIR} ${DOCSDIR}/ru
	${INSTALL_DATA} ${WRKSRC}/doc/EN/index.html ${DOCSDIR}/en
	${INSTALL_DATA} ${WRKSRC}/doc/RU/index.html ${DOCSDIR}/ru
.endif

.include <bsd.port.mk>
