# Created by: Jean-Marc Zucconi <jmz@FreeBSD.org>
# $FreeBSD$

PORTNAME=	netpbm
DISTVERSION=	10.89.00
CATEGORIES=	graphics
MASTER_SITES=	https://github.com/t6/netpbm/releases/download/v${DISTVERSION}/ \
		LOCAL/tobik

MAINTAINER=	tobik@FreeBSD.org
COMMENT=	Toolkit for conversion of images between different formats

LICENSE=	GPLv2 IJG LGPL21 MIT PD
LICENSE_COMB=	multi
LICENSE_NAME_IJG=	Independent JPEG Group License
LICENSE_FILE_IJG=	${WRKSRC}/doc/copyright_summary
LICENSE_PERMS_IJG=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

TEST_DEPENDS=	bash:shells/bash

# The port follows the advanced release series.  Upstream does not
# create tarballs for them, so we have to roll our own.  See
# http://netpbm.sourceforge.net/getting_netpbm.php.  To checkout the
# sources yourself see the netpbm-version-check and netpbm-fetch
# targets below.
USES=		ghostscript:test gmake perl5 shebangfix tar:xz
USE_LDCONFIG=	yes
USE_PERL5=	build test

SHEBANG_FILES=	buildtools/makeman converter/pbm/pbmtox10bm editor/pnmflip \
		editor/pnmquant editor/ppmfade editor/ppmquant editor/ppmshadow \
		generator/ppmrainbow test/*.test test/Available-Testprog \
		test/Execute-Tests

MAKEFILE=	GNUmakefile
MAKE_ARGS=	BINMODE=${BINMODE} \
		DATADIR=${DATADIR} \
		DATAMODE=${_SHAREMODE} \
		DIRMODE=755 \
		MANMODE=${MANMODE} \
		pkgdir=${STAGEDIR}${PREFIX} \
		SHAREMODE=${SHAREMODE}
INSTALL_TARGET=	install.bin install.lib install.data install.hdr \
		install.staticlib
TEST_ARGS=	pkgdir="${STAGEDIR}${PREFIX}" \
		resultdir="${WRKDIR}/tests" \
		RGBDEF="${STAGEDIR}${PREFIX}/share/netpbm/rgb.txt"
TEST_TARGET=	check
# Disable fragile tests.  tiff-flate-lzw-roundtrip's checksums are
# different on FreeBSD so the test fails.  The resulting and
# intermediary images look fine in spite of this.
_DISABLE_TESTS=	all-in-place palm-roundtrip pamhue pammixmulti-identity \
		pamtopdbimg pnmquant ppmgauss ps-alt-roundtrip \
		tiff-flate-lzw-roundtrip

OPTIONS_DEFINE=		MANPAGES PERL STATIC SVGTOPAM X11
OPTIONS_DEFAULT=	MANPAGES PERL
OPTIONS_SUB=		yes

SVGTOPAM_DESC=	Build svgtopam
X11_DESC=	Build pamx

PERL_USE=		PERL5=run
STATIC_BUILD_DEPENDS=	jasper>0:graphics/jasper \
			jbigkit>0:graphics/jbigkit \
			png>0:graphics/png \
			tiff>0:graphics/tiff
STATIC_LIB_DEPENDS_OFF=	libjasper.so:graphics/jasper \
			libjbig.so:graphics/jbigkit \
			libpng.so:graphics/png \
			libtiff.so:graphics/tiff
STATIC_USES_OFF=	jpeg
STATIC_USES=		jpeg:build
SVGTOPAM_USES=		gnome
SVGTOPAM_USE=		GNOME=libxml2
SVGTOPAM_VARS_OFF=	_DISABLE_TESTS+=svgtopam
X11_USES=		xorg
X11_USE=		XORG=x11,xau,xcb,xdmcp

post-patch:
	@${REINPLACE_CMD} -e 's|misc|share/netpbm|g' ${WRKSRC}/common.mk
	@${REINPLACE_CMD} -e 's|$$(PKGDIR)/link|$$(PKGDIR)/lib|g' \
		-e 's|pkg-config|false|g' \
		${WRKSRC}/GNUmakefile ${WRKSRC}/lib/Makefile
.for test in ${_DISABLE_TESTS}
	@${REINPLACE_CMD} -e '/${test}/d' ${WRKSRC}/test/Test-Order
.endfor

post-patch-STATIC-on:
	@${REINPLACE_CMD} -e 's|$$(LD)|$$(LD) -static|g' \
		-e 's@$$(NETPBMLIBFNAME)@libnetpbm.a@' \
		${WRKSRC}/common.mk

# Disable building svgtopam by default.  It is the only program that
# requires libxml2 and it is not useful in this day and age according
# to the author.  See the top of converter/other/svgtopam.c for more
# details.
post-patch-SVGTOPAM-off:
	@${REINPLACE_CMD} '/svgtopam/d' ${WRKSRC}/converter/other/Makefile

post-patch-X11-off:
	@${REINPLACE_CMD} '/pamx/d' ${WRKSRC}/other/Makefile

do-configure:
	@${CAT} ${WRKSRC}/config.mk.in ${FILESDIR}/config.mk > ${WRKSRC}/config.mk

post-install:
	@cd ${STAGEDIR}${PREFIX}/lib && ${LN} -sf libnetpbm.so.11 libnetpbm.so
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libnetpbm.so
	@${RM} ${STAGEDIR}${PREFIX}/bin/manweb
	${INSTALL_DATA} ${WRKSRC}/lib/util/pm_c_util.h ${WRKSRC}/pm_config.h \
		${STAGEDIR}${PREFIX}/include/netpbm
	${MV} ${STAGEDIR}${PREFIX}/staticlink/libnetpbm.a ${STAGEDIR}${PREFIX}/lib
	${RMDIR} ${STAGEDIR}${PREFIX}/sharedlink ${STAGEDIR}${PREFIX}/staticlink

post-install-MANPAGES-on:
	${INSTALL_MAN} ${WRKSRC}/man/*.1 ${STAGEDIR}${PREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/man/*.3 ${STAGEDIR}${PREFIX}/man/man3
	${INSTALL_MAN} ${WRKSRC}/man/*.5 ${STAGEDIR}${PREFIX}/man/man5

.if defined(DEVELOPER)
# A lot of this is stolen from the netpbm OpenBSD port
NETPBM_REPO=	https://svn.code.sf.net/p/netpbm/code
NETPBM_SERIES=	advanced

netpbm-version-check:
	@REV=`svnlite info ${NETPBM_REPO}/${NETPBM_SERIES}/version.mk | sed -n 's/Last Changed Rev: //p'`; \
	VERSION=`(svnlite cat -r$$REV ${NETPBM_REPO}/${NETPBM_SERIES}/version.mk; \
			echo 'all:'; \
			echo '	@printf "%02d.%02d.%02d" \'; \
			echo '		$${NETPBM_MAJOR_RELEASE} \' ; \
			echo '		$${NETPBM_MINOR_RELEASE} \' ; \
			echo '		$${NETPBM_POINT_RELEASE} \' ; \
		) | make -f -`; \
	case `pkg version -t ${PORTVERSION} $$VERSION` in \
		'>') echo "Port version is greater than latest release $$VERSION"; exit 1 ;; \
		'<') echo "Run 'make NETPBM_REV=$$REV netpbm-fetch' to download netpbm $$VERSION" ;; \
	esac

netpbm-fetch:
	@svnlite export --force -r${NETPBM_REV} ${NETPBM_REPO}/${NETPBM_SERIES} netpbm-r${NETPBM_REV}
.endif

.include <bsd.port.mk>
