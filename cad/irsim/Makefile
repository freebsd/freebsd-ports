PORTNAME=	irsim
DISTVERSION=	9.7.119
CATEGORIES=	cad
MASTER_SITES=	http://opencircuitdesign.com/irsim/archive/
PKGNAMESUFFIX=	-${FLAVOR}

MAINTAINER=	alven@FreeBSD.org
COMMENT=	Event-driven logic-level simulator for MOS circuis
WWW=		http://opencircuitdesign.com/irsim/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYRIGHT

FLAVORS=	scheme lite tcl
FLAVOR?=	${FLAVORS:[1]}

lite_CONFLICTS_INSTALL=		${PORTNAME}-scheme ${PORTNAME}-tcl
scheme_CONFLICTS_INSTALL=	${PORTNAME}-lite   ${PORTNAME}-tcl
tcl_CONFLICTS_INSTALL=		${PORTNAME}-lite   ${PORTNAME}-scheme

USES=		gmake localbase:ldflags tar:tgz xorg
USE_XORG=	x11

GNU_CONFIGURE=	yes

CONFIGURE_WRKSRC=	${WRKSRC}/scripts

PLIST=		pkg-plist.${FLAVOR}

.if ${FLAVOR} == lite
CONFIGURE_ARGS=		--with-interpreter=no
WISH=			${FALSE}
.elif ${FLAVOR} == scheme
CONFIGURE_ARGS=		--with-interpreter=scheme
WISH=			${FALSE}
.elif ${FLAVOR} == tcl
CONFIGURE_ARGS=		--with-interpreter=tcl
# Workaround building Tcl with clang17+
# See https://github.com/RTimothyEdwards/irsim/issues/7
LDFLAGS+=		-Wl,--undefined-version
USES+=			tk:tea
.endif

post-patch:
	@${REINPLACE_CMD} -e \
		's|FreeBSD-\*|*-*-freebsd*| ; \
		 s|wish |${WISH:T} | ; \
		 s|"-fpic"|"-fPIC"| ; \
		 /-l\/usr\/X11R6\/include/d' ${CONFIGURE_WRKSRC}/configure

post-install:
.if ${FLAVOR} == tcl
	cd ${STAGEDIR}${PREFIX}/lib/irsim/tcl && \
		${STRIP_CMD} diglib.so irsimexec random.so tclirsim.so
.else
	cd ${STAGEDIR}${PREFIX}/bin && ${STRIP_CMD} irsim genspktbl gentbl
.endif

.include <bsd.port.mk>
