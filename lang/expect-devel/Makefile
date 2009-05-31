# New ports collection makefile for:	expect-devel
# Date created:		17 October 2007
# Whom:			mm
#
# $FreeBSD$

PORTNAME=	expect
PORTVERSION=	5.44.1.11
PORTREVISION=	1
CATEGORIES=	lang tcl tk
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	wintcltk
DISTNAME=	expect-cvs-20081121

MAINTAINER=	mm@FreeBSD.org
COMMENT=	A sophisticated scripter based on tcl/tk

CONFLICTS=	expect-5.43*
LATEST_LINK=	expect-devel

USE_AUTOTOOLS=	autoconf:262

EXPECT_VER=	${PORTVERSION}

.if !defined(WITHOUT_X11)
USE_TK=		84+
.else
PKGNAMESUFFIX=	-nox11
USE_TCL=	84+
.endif

WRKSRC=		${WRKDIR}/expect
USE_LDCONFIG=	${PREFIX}/lib/expect${EXPECT_VER}
GNU_CONFIGURE=	yes

PLIST_SUB+=	EXPECT_VER="${EXPECT_VER}"

.include <bsd.port.pre.mk>

.if defined(WITHOUT_X11)
TK_CONFIG_ARGS=
PLIST_SUB+=	XFILES="@comment "
.else
USE_XORG=	x11
TK_CONFIG_ARGS=	--with-tkconfig=${TK_LIBDIR} \
		--with-tkinclude=${TK_INCLUDEDIR}
CFLAGS+=	-I${LOCALBASE}/include -I${TK_INCLUDEDIR} -I${TK_INCLUDEDIR}/generic
PLIST_SUB+=	XFILES=""
.endif

CONFIGURE_ARGS+=--enable-shared \
		--with-tclconfig=${TCL_LIBDIR} \
		--with-tclinclude=${TCL_INCLUDEDIR} \
		${TK_CONFIG_ARGS}

CFLAGS+=	-I${TCL_INCLUDEDIR} -I${TCL_INCLUDEDIR}/generic

.if !defined(NO_MAN_INSTALL)
MAN1=		autoexpect.1 cryptdir.1 decryptdir.1 dislocate.1 \
		expect.1 kibitz.1 mkpasswd.1 passmass.1 unbuffer.1 xkibitz.1
.if !defined(WITHOUT_X11)
MAN1+=		expectk.1 multixterm.1 tknewsbiff.1
.endif
MAN3=		libexpect.3
.endif

post-patch:
.if defined(WITHOUT_X11)
	@${REINPLACE_CMD} -e 's/TEA_PATH_TKCONFIG//g' \
		-e 's/TEA_LOAD_TKCONFIG//g' -e 's/TEA_PUBLIC_TK_HEADERS//g' \
		${WRKSRC}/configure.in
	@${REINPLACE_CMD} -e 's/expect expectk/expect/g' \
		-e 's/multixterm//g' -e 's/tknewsbiff//g' -e 's/tkpasswd//g' \
		-e 's/xpstat//g' -e 's/@TK_INCLUDES@//g' \
		-e 's|$$(INSTALL_DATA) $$(srcdir)/expectk.man|#|g' \
		${WRKSRC}/Makefile.in
.endif

pre-configure:
	${TOUCH} ${WRKSRC}/configure
	@cd ${WRKSRC}/testsuite && ${AUTOCONF} -I ..

.include <bsd.port.post.mk>
