# New ports collection makefile for:	TEA
# Date created:				13 Jul 2004
# Whom:					Jean-Yves Lefort <jylefort@brutele.be>
#
# $FreeBSD$
#

PORTNAME=		tea
PORTVERSION=		8.1
CATEGORIES=		editors
MASTER_SITES=		http://tea.linux.kiev.ua/
DISTNAME=		${PORTNAME}

MAINTAINER=		jylefort@brutele.be
COMMENT=		A simple and powerful GTK+ text editor

WRKSRC=			${WRKDIR}/${PORTNAME}-${PORTVERSION}

USE_X_PREFIX=		yes
USE_BZIP2=		yes
USE_REINPLACE=		yes
GNU_CONFIGURE=		yes
USE_GCC=		3.4
USE_GNOME=		gtk20
CONFIGURE_ENV=		CPPFLAGS="-I${LOCALBASE}/include" \
			LDFLAGS="-L${LOCALBASE}/lib"

OPTIONS=		ASPELL "Build with GNU aspell support" off

.include <bsd.port.pre.mk>

.if defined(WITH_ASPELL)
LIB_DEPENDS+=		aspell:${PORTSDIR}/textproc/aspell
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|/tea/doc/|/doc/tea/|' \
		${WRKSRC}/src/tea_defs.h

.include <bsd.port.post.mk>
