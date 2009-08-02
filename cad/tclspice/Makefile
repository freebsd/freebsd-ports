# New ports collection makefile for:	tclspice
# Date created:		2006-06-24
# Whom:			Stanislav Sedov <stas@fonon.realnet>
#
# $FreeBSD$
#

PORTNAME=	tclspice
PORTVERSION=	0.2.18
PORTREVISION=	4
CATEGORIES=	cad
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	tclspice

MAINTAINER=	ssedov@mbsd.msk.ru
COMMENT=	Improved version on SPICE3 suite with TCL scripting features

BUILD_DEPENDS=	bltwish:${PORTSDIR}/x11-toolkits/blt \
		${LOCALBASE}/lib/libtclreadline.so:${PORTSDIR}/devel/tclreadline
RUN_DEPENDS=	bltwish:${PORTSDIR}/x11-toolkits/blt \
		${LOCALBASE}/lib/libtclreadline.so:${PORTSDIR}/devel/tclreadline

WRKSRC=		${WRKDIR}/${PORTNAME}
USE_AUTOTOOLS=	aclocal:19 automake:19 autoconf:262 libtool:22
AUTOMAKE_ARGS=	-c -a
USE_GMAKE=	yes
ALL_TARGET=	tcl
INSTALL_TARGET=	install-tcl
USE_LDCONFIG=	yes

SUB_FILES=	pkg-message

OPTIONS=	EXPERIMENTAL "Enable experimental features" on \
		EXAMPLES "Install sample scripts" on

CONFIGURE_ARGS=	--with-tcl=${LOCALBASE}/lib/tcl8.4
CONFIGURE_ENV=	CFLAGS="-I${LOCALBASE}/include ${CFLAGS} -fPIC" \
		LDFLAGS="-L${LOCALBASE}/lib -ltcl84 -lBLT24"
ACLOCAL_ARGS=	--acdir=${ACLOCAL_DIR} -I ${LOCALBASE}/share/aclocal

WISH=		${LOCALBASE}/bin/wish8.4

.include <bsd.port.pre.mk>

.if !defined(WITHOUT_EXPERIMENTAL)
CONFIGURE_ARGS+=	--enable-experimental
.endif

.if !defined(WITHOUT_EXAMPLES)
PLIST_SUB+=	EXAMPLES=""
.else
PLIST_SUB+=	EXAMPLES="@comment "
.endif

post-patch:
.for FILE in spicewish tcl/plot.tcl tcl/vector_test.tcl
	@${REINPLACE_CMD} -e 's|%%WISH%%|${WISH}|g' ${WRKSRC}/src/${FILE}
.endfor

post-install:
.if !defined(WITHOUT_EXAMPLES)
	@${MKDIR} ${EXAMPLESDIR}
.for FILE in README example.cir plot.tcl vector_test.tcl
	@${INSTALL_DATA} ${WRKSRC}/src/tcl/${FILE} ${EXAMPLESDIR}
.endfor
	@${CAT} ${PKGMESSAGE}
.endif

.include <bsd.port.post.mk>
