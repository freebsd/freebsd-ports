# New ports collection makefile for: 	tcllib
# Date created:				27 Apr 2000
# Whom:					Mikhail Teterin <mi@aldan.algebra.com>
#
# $FreeBSD$
#

PORTNAME=		tcllib
PORTVERSION=		1.9
PORTREVISION=		1
CATEGORIES=		devel tcl83 tcl84
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	tcllib

MAINTAINER=	mi@aldan.algebra.com
COMMENT=	A collection of utility modules for Tcl

BUILD_DEPENDS=	tclsh${TCL_VER}:${PORTSDIR}/lang/tcl${TCL_VER:S/.//}
USE_TCL_BUILD=	yes
USE_TCL_RUN=	${USE_TCL_BUILD}

USE_BZIP2=	yes
GNU_CONFIGURE=	yes
ALL_TARGET=	all
MAKE_ENV+=	LANG=C

PLIST_SUB+=	PORTVERSION=${PORTVERSION}

MANN=	aes.n asn.n ansi_cmacros.n ansi_cctrl.n ansi_cattr.n           \
	ansi_code.n ansi_ctrlu.n ansi_send.n autoproxy.n base32hex.n   \
	base32core.n base32.n base64.n bee.n bibtex.n bigfloat.n       \
	bignum.n blowfish.n calculus.n changelog.n cksum.n cmdline.n   \
	combinatorics.n comm.n comm_wire.n connect.n constants.n       \
	control.n copyops.n counter.n crc16.n crc32.n csv.n cvs.n      \
	dacceptor.n ddest.n deleg_method.n deleg_proc.n des.n dexec.n  \
	docidx.n docidx_api.n docidx_fmt.n docstrip.n docstrip_util.n  \
	doctoc.n doctoc_api.n doctoc_fmt.n doctools.n doctools_api.n   \
	doctools_fmt.n dsource.n dtplite.n exif.n expander.n fa.n      \
	faop.n filetypes.n fileutil.n fourier.n ftp.n ftpd.n fuzzy.n   \
	geometry.n graph.n graph1.n html.n htmlparse.n ident.n         \
	imenu.n ini.n interpolate.n ipager.n irc.n javascript.n        \
	jpeg.n json.n ldap.n ldapx.n linalg.n log.n logger.n           \
	loggerAppender.n loggerUtils.n math.n matrix.n matrix1.n md4.n \
	md5.n md5crypt.n me_ast.n me_cpu.n me_cpucore.n me_intro.n     \
	me_tcl.n me_util.n me_vm.n mime.n mimetypes.n mpexpand.n       \
	multiplexer.n ncgi.n nmea.n nntp.n ntp_time.n otp.n optimize.n \
	page.n peg.n peg_interp.n pluginmgr.n png.n polynomials.n      \
	pool.n pop3.n pop3d.n pop3d_dbox.n pop3d_udb.n prioqueue.n     \
	profiler.n qcomplex.n queue.n rational_funcs.n rc4.n rcs.n     \
	record.n receive.n receiver.n report.n ripemd128.n             \
	ripemd160.n roman.n romberg.n sasl.n sha1.n skiplist.n         \
	smtp.n smtpd.n snit.n snitfaq.n soundex.n special.n stack.n    \
	statistics.n stooop.n struct_list.n struct_set.n struct_tree.n \
	struct_tree1.n sum.n tar.n tcllib_interp.n tcllib_ip.n term.n  \
	term_send.n term_bind.n tcldocstrip.n tcllib_dns.n textutil.n  \
	tie.n tiff.n tqueue.n transmitter.n treeql.n units.n uri.n     \
	uuencode.n uuid.n yencode.n

MANCOMPRESSED=	no

.include <bsd.port.pre.mk>

CONFIGURE_ENV+=	ac_cv_path_tclsh="${TCLSH}"

post-patch:
	#
	# Ensure, the detailed output of vendors' self-tests is
	# available in addition to the pretty progress report:
	#
	${REINPLACE_CMD} -e 's,test run,test run -l testlog,' \
		${WRKSRC}/Makefile.in
	${REINPLACE_CMD} -e 's,exec tclsh,exec ${TCLSH},'	\
		${WRKSRC}/apps/dtplite

RUNTEST=	${SETENV} LANG=C DISPLAY= ${MAKE} -C ${WRKSRC} test
MYID	!=	${ID} -u
.if ${MYID} == 0
RUNTEST:=	${SU_CMD:S/root/-m nobody/} "${RUNTEST}"
pre-build:
	#
	# Preparing to run the tests as `nobody'
	#
	${FIND} ${WRKSRC} -type d | ${XARGS} ${CHOWN} nobody
.endif

test:
	@set -x ; if ! ${RUNTEST};	\
	then	\
		${AWK} '$$NF == "FAILED" { echo = 1 }	\
			echo { if ($$NF == "start") echo = 0; else print }'	\
				${WRKSRC}/testlog.log;	\
		${CAT} ${WRKSRC}/testlog.failures;	\
		${UNAME} -a;	\
		${ECHO_MSG} Please, analyze and report the test failures;	\
	fi

post-build:	test

.include <bsd.port.post.mk>
