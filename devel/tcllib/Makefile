# New ports collection makefile for: 	tcllib
# Date created:				27 Apr 2000
# Whom:					Mikhail Teterin <mi@aldan.algebra.com>
#
# $FreeBSD$
#

PORTNAME=		tcllib
PORTVERSION=		1.7
PORTREVISION=		1
CATEGORIES=		devel tcl83 tcl84
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	tcllib

MAINTAINER=	mi@aldan.algebra.com
COMMENT=	A collection of utility modules for Tcl

BUILD_DEPENDS=	tclsh:${PORTSDIR}/lang/tcl${TCL_VER:S/.//}

TCL_VER?=	8.4
USE_BZIP2=	yes
GNU_CONFIGURE=	yes
ALL_TARGET=	all
MAKE_ENV+=	LANG=C
SCRIPTS_ENV+=	TCL_VER=${TCL_VER} PATCH="${PATCH}"

PLIST_SUB+=	PORTVERSION=${PORTVERSION}

MANN=	asn.n autoproxy.n base64.n bee.n bignum.n calculus.n changelog.n\
	cksum.n cmdline.n combinatorics.n comm.n constants.n control.n\
	counter.n crc16.n crc32.n csv.n cvs.n dacceptor.n des.n dexec.n\
	docidx.n docidx_api.n docidx_fmt.n doctoc.n doctoc_api.n doctoc_fmt.n\
	doctools.n doctools_api.n doctools_fmt.n dtplite.n exif.n expander.n\
	fa.n faop.n fileutil.n fourier.n ftp.n ftpd.n fuzzy.n geometry.n\
	graph.n graph1.n html.n htmlparse.n ident.n ini.n interpolate.n\
	irc.n javascript.n jpeg.n ldap.n log.n logger.n math.n matrix.n\
	matrix1.n md4.n md5.n md5crypt.n mime.n mpexpand.n multiplexer.n\
	ncgi.n nntp.n ntp_time.n optimize.n png.n polynomials.n pool.n\
	pop3.n pop3d.n pop3d_dbox.n pop3d_udb.n prioqueue.n profiler.n\
	qcomplex.n queue.n rc4.n record.n report.n ripemd128.n ripemd160.n\
	romberg.n sha1.n skiplist.n smtp.n smtpd.n snit.n snitfaq.n soundex.n\
	special.n stack.n statistics.n stooop.n struct_list.n struct_set.n\
	struct_tree.n struct_tree1.n sum.n tar.n tcllib_dns.n tcllib_ip.n\
	textutil.n tie.n treeql.n uri.n uuencode.n uuid.n yencode.n\

MANCOMPRESSED=	no

test:
.ifdef DISPLAY
	#
	# DISPLAY environment variable appears to be set (${DISPLAY}).
	# Tcllib may perform some additional Tk-only tests.
	#
	-${TEST} -t 1 && sleep 2
.endif
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE} test

.include <bsd.port.pre.mk>

.if ${ARCH} == "i386"
post-build:	test
.else
post-build:
	# Build is over quickly...
	#
	# Several of tcllib's tests are known to hang/fail on non-i386
	# architectures (not only on ${OPSYS}) so testing on your
	# (${ARCH}) system is not performed automatically. You are
	# encouraged to run `make test' manually, however, to check if
	# the parts, that are important to you, are problem-free.
	#
.endif

.include <bsd.port.post.mk>
