# Created by: roam@FreeBSD.org
# $FreeBSD$

PORTNAME=	gecode
PORTVERSION=	3.7.3
CATEGORIES=	devel
MASTER_SITES=	http://www.gecode.org/download/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Generic Constraint Development Environment

LICENSE=	MIT

OPTIONS_DEFINE=	GIST
GIST_DESC=	Interactive Search Tool (requires Qt)

USE_PERL5=	build
USES=		bison perl5
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-static \
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
USE_LDCONFIG=	yes
MAKE_JOBS_UNSAFE=yes

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MGIST}
USE_QT4=	corelib gui moc_build qmake_build
CONFIGURE_ARGS+=--enable-gist --enable-qt
PLIST_SUB+=	GIST=""
.else
CONFIGURE_ARGS+=--disable-gist --disable-qt
PLIST_SUB+=	GIST="@comment "
.endif

post-patch:
	@${REINPLACE_CMD} -e \
		'/^ARR/s|^|#| ; \
		 /^PACKAGE_VERSION_NUMBER/s|^|#| ; \
		 /_vendor/s| == | = | ; \
		 /host_os/s| == | = | ; \
		 /gcc_optimize_flag/s|-O3|| ; \
		 /="-ggdb/s|^|#|' ${WRKSRC}/configure

.include <bsd.port.mk>
