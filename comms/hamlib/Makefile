# New ports collection makefile for:	hamlib
# Date created:			30 April 2003
# Whom:				Sebastian Yepes <esn@x123.info>
#
# $FreeBSD$
#

PORTNAME=	hamlib
PORTVERSION=	1.2.13
CATEGORIES=	comms hamradio
MASTER_SITES=	SF

MAINTAINER=	db@FreeBSD.org
COMMENT=	Shared libraries for Amateur Radio Equipment Control Applications

BUILD_DEPENDS=	swig:${PORTSDIR}/devel/swig13

USE_GNOME=	pkgconfig gnomehack libxml2
USE_PERL5=	yes
USE_TCL=	yes
USE_PYTHON=	yes
USE_AUTOTOOLS=	autoconf libtool libltdl
USE_LDCONFIG=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" LIBS="-L${LOCALBASE}/lib"
CONFIGURE_ARGS=	--with-perl-binding --with-python=${PYTHON_CMD} \
		--enable-tcl-binding --with-tcl=${TCL_LIBDIR} \
		--with-python-binding --without-with-rigmatrix
PLIST_SUB=	VER=${PORTVERSION} TCL_VER=${TCL_VER}

MAN1=		rigctl.1 rigmem.1 rigswr.1 rotctl.1 rigsmtr.1
MAN8=		rpc.rigd.8 rpc.rotd.8 rigctld.8 rotctld.8

post-patch:
	${REINPLACE_CMD} -e 's|%%PYTHON_SITELIBDIR%%|${PYTHON_SITELIBDIR}|g' \
		-e 's|%%TCL_LIBDIR%%|${TCL_LIBDIR}/hamlib|g' \
		${WRKSRC}/bindings/Makefile.in
	${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|g' \
		${WRKSRC}/src/Makefile.in
post-build:
	${PERL5} -pi -e 's/ doc_(perl|site|\$$\(INSTALLDIRS\))_install$$//' \
		${WRKSRC}/bindings/Hamlib-pl.mk

post-install:
.if	!defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for d in ${WRKSRC}/AUTHORS ${WRKSRC}/COPYING ${WRKSRC}/COPYING.LIB \
	${WRKSRC}/ChangeLog ${WRKSRC}/INSTALL ${WRKSRC}/LICENSE \
	${WRKSRC}/NEWS ${WRKSRC}/PLAN ${WRKSRC}/README \
	${WRKSRC}/README.betatester ${WRKSRC}/README.win32 \
	${WRKSRC}/THANKS
	${INSTALL_DATA} ${WRKSRC}/${d} ${DOCSDIR}
.endfor
	@${ECHO}
	@${ECHO} "docs installed in ${DOCSDIR}"
	@${ECHO}
.endif

.include <bsd.port.mk>
