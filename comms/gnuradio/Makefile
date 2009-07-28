## ports collection makefile for:	gnuradio
# Date created:		2 January 2006
# Whom:			db
#
# $FreeBSD$
#

PORTNAME=	gnuradio
PORTVERSION=	3.1.3
PORTREVISION=	2
CATEGORIES=	comms astro hamradio
MASTER_SITES=	${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	gnuradio
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	db@FreeBSD.org
COMMENT=	Amateur Radio Software defined radio

BUILD_DEPENDS=	sdcc:${PORTSDIR}/lang/sdcc \
		sdl-config:${PORTSDIR}/devel/sdl12 \
		swig:${PORTSDIR}/devel/swig13 \
		cppunit-config:${PORTSDIR}/devel/cppunit \
		guile:${PORTSDIR}/lang/guile
LIB_DEPENDS=	fftw3:${PORTSDIR}/math/fftw3 \
		fftw3f:${PORTSDIR}/math/fftw3-float \
		boost_python:${PORTSDIR}/devel/boost-python-libs
RUN_DEPENDS=	${PYNUMPY} \
		${PYTHON_SITELIBDIR}/ephem/__init__.py:${PORTSDIR}/astro/pyephem

USE_PYTHON=	2.4+
USE_WX=		2.6+
WX_COMPS=	wx wx:build wx:run python:build python:run
USE_PERL5=	yes
USE_AUTOTOOLS=	autoconf:262 libtool:15
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

CONFIGURE_ARGS=	--with-boost-include-dir="${LOCALBASE}/include/" \
		--enable-usrp \
		--enable-gr-usrp \
		--disable-gr-audio-jack \
		--disable-gr-audio-portaudio \
		--enable-gr-audio-oss \
		--enable-gr-wxgui \
		--enable-gnuradio-examples \
		--disable-doxygen \
		--disable-html-docs \
		--disable-latex-docs

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 800069
LIB_DEPENDS+=	usb:${PORTSDIR}/devel/libusb
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|2.61|2.62|g' ${WRKSRC}/aclocal.m4
	@${FIND} ${WRKSRC} -type f -name "Makefile.in" | ${XARGS} \
		-n 10 ${REINPLACE_CMD} -E -e \
		's!^(ACLOCAL|AUTOCONF|AUTOMAKE|AUTOHEADER).+$$!\1=${TRUE}!' \
		-e 's|/gnuradio/examples|/examples/gnuradio|'
	@${REINPLACE_CMD} -e 's|%%LIBDATA%%|${PREFIX}/libdata|' \
	    ${WRKSRC}/gnuradio-core/Makefile.in ${WRKSRC}/usrp/Makefile.in \
	    ${WRKSRC}/omnithread/Makefile.in ${WRKSRC}/gr-atsc/Makefile.in
pre-install:
	@${CP}	${FILESDIR}/wxgui_src_python_init.py \
		${WRKSRC}/gr-wxgui/src/python/__init__.py
post-install:
	@${INSTALL_DATA}	${WRKSRC}/gnuradio-core/gnuradio-core.conf \
	    ${PREFIX}/etc/gnuradio/gnuradio-core.conf.sample
	@${INSTALL_DATA}	${WRKSRC}/gr-audio-oss/gr-audio-oss.conf \
	    ${PREFIX}/etc/gnuradio/gr-audio-oss.conf.sample
	@${INSTALL_DATA}	${WRKSRC}/gr-wxgui/gr-wxgui.conf \
	    ${PREFIX}/etc/gnuradio/gr-wxgui.conf.sample
.if	!defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.hacking ${DOCSDIR}
	@${ECHO} gnuradio docs are in ${DOCSDIR}
.endif
	@${ECHO} sample conf files are in ${PREFIX}/etc/gnuradio
	@${ECHO} These must be copied to ${PREFIX}/etc/gnuradio/conf.d
	@${ECHO} without the .sample suffix and edited as needed before use.
	@${ECHO}

.include <bsd.port.post.mk>
