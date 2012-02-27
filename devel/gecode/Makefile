# New ports collection makefile for:	gecode
# Date created:				24 January 2011
# Whom:					roam@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	gecode
PORTVERSION=	3.5.0
CATEGORIES=	devel
MASTER_SITES=	http://www.gecode.org/download/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Generic Constraint Development Environment

BUILD_DEPENDS=	bison>=2.3:${PORTSDIR}/devel/bison \
		flex>=2.5.35:${PORTSDIR}/textproc/flex

LICENSE=	MIT
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
USE_PERL5_BUILD=	yes

MAKE_JOBS_UNSAFE=	yes
PATCH_STRIP=	-p1

OPTIONS=	GIST "Interactive Search Tool" off \
		QT "QT interface" off

.include <bsd.port.options.mk>

.if defined(WITH_QT)
CONFIGURE_ARGS+=	--enable-qt
USE_QT_VER=		4
QT_COMPONENTS=		corelib gui moc_build qmake_build
.else
CONFIGURE_ARGS+=	--disable-qt
.endif

.if defined(WITH_GIST)
.if !defined(WITH_QT)
IGNORE=			Building GIST requires enabling the QT interface
.else
CONFIGURE_ARGS+=	--enable-gist
PLIST_SUB+=		GIST=""
.endif
.else
CONFIGURE_ARGS+=	--disable-gist
PLIST_SUB+=		GIST="@comment "
.endif

CONFIGURE_ARGS+=\
		--disable-static \
		--enable-shared \
		--disable-doc-dot \
		--disable-doc-tagfile \
		--disable-doc-chm \
		--enable-driver \
		--enable-graph \
		--enable-flatzinc \
		--enable-sheduling \
		--disable-examples \
		--enable-minimodel \
		--enable-search

.include <bsd.port.mk>
