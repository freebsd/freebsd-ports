# New ports collection makefile for: 	tcllib
# Date created:				27 Apr 2000
# Whom:					Mikhail Teterin <mi@aldan.algebra.com>
#
# $FreeBSD$
#

PORTNAME=		tcllib
PORTVERSION=		1.11
CATEGORIES=		devel tcl
MASTER_SITES=		SF

MAINTAINER=	mi@aldan.algebra.com
COMMENT=	A collection of utility modules for Tcl

USE_TCL_BUILD=	82+
USE_TCL_RUN=	${USE_TCL_BUILD}

USE_BZIP2=	yes
GNU_CONFIGURE=	yes
ALL_TARGET=	all
MAKE_ENV+=	LANG=C

.if defined(NO_INSTALL_MANPAGES)
INSTALL_TARGET=	install-libraries install-applications
.else
MANN=	S3.n adjust.n aes.n annealing.n		\
	ansi_cattr.n ansi_cctrl.n ansi_cmacros.n ansi_code.n	\
	ansi_ctrlu.n ansi_send.n asn.n autoproxy.n base32.n	\
	base32core.n base32hex.n base64.n bee.n bibtex.n bigfloat.n	\
	bignum.n blowfish.n calculus.n cfront.n cgen.n		\
	changelog.n cksum.n cmdline.n	\
	combinatorics.n comm.n comm_wire.n connect.n constants.n	\
	control.n copyops.n counter.n crc16.n crc32.n csv.n cvs.n	\
	dacceptor.n ddest.n deleg_method.n deleg_proc.n des.n	\
	dexec.n disjointset.n	\
	docidx.n docidx_intro.n docidx_lang_cmdref.n	\
	docidx_lang_faq.n docidx_lang_intro.n docidx_lang_syntax.n	\
	docidx_plugin_apiref.n docstrip.n docstrip_util.n doctoc.n	\
	doctoc_intro.n doctoc_lang_cmdref.n doctoc_lang_faq.n	\
	doctoc_lang_intro.n doctoc_lang_syntax.n doctoc_plugin_apiref.n	\
	doctools.n doctools_intro.n doctools_lang_cmdref.n	\
	doctools_lang_faq.n doctools_lang_intro.n doctools_lang_syntax.n	\
	doctools_plugin_apiref.n dsource.n dtplite.n exif.n	\
	expander.n fa.n faop.n filetypes.n fileutil.n fourier.n	\
	ftp.n ftp_geturl.n	\
	ftpd.n fuzzy.n gasm.n	\
	geometry.n graph.n graph1.n html.n	\
	htmlparse.n huddle.n	\
	ident.n imenu.n ini.n interpolate.n ipager.n	\
	irc.n javascript.n jpeg.n json.n ldap.n ldapx.n linalg.n	\
	log.n logger.n loggerAppender.n loggerUtils.n mapproj.n	\
	math.n matrix.n matrix1.n md4.n md5.n md5crypt.n me_ast.n	\
	me_cpu.n me_cpucore.n me_intro.n me_tcl.n me_util.n me_vm.n	\
	mime.n mimetypes.n montecarlo.n	\
	mpexpand.n multi.n multiop.n multiplexer.n	\
	ncgi.n nmea.n nns_auto.n nns_client.n nns_common.n	\
	nns_intro.n	\
	nns_protocol.n nns_server.n	\
	nntp.n ntp_time.n optimize.n	\
	otp.n page.n page_intro.n page_pluginmgr.n page_util_flow.n	\
	page_util_norm_lemon.n page_util_norm_peg.n page_util_peg.n	\
	page_util_quote.n peg.n peg_interp.n picoirc.n	\
	pluginmgr.n png.n	\
	polynomials.n pool.n pop3.n pop3d.n pop3d_dbox.n pop3d_udb.n	\
	prioqueue.n profiler.n qcomplex.n queue.n random.n	\
	rational_funcs.n	\
	rc4.n rcs.n receive.n receiver.n record.n repeat.n	\
	report.n ripemd128.n	\
	ripemd160.n roman.n romberg.n rtcore.n	\
	sasl.n sha1.n sha256.n	\
	skiplist.n	\
	smtp.n smtpd.n snit.n snitfaq.n soundex.n special.n stack.n	\
	statistics.n stooop.n stringprep.n stringprep_data.n	\
	struct_list.n struct_set.n struct_tree.n	\
	struct_tree1.n sum.n tabify.n tar.n tcldocstrip.n tcllib_dns.n	\
	tcllib_interp.n tcllib_ip.n term.n term_bind.n term_send.n	\
	textutil.n textutil_split.n textutil_string.n	\
	tie.n tie_std.n	\
	tiff.n tqueue.n transmitter.n traverse.n	\
	treeql.n trim.n	\
	uevent.n unicode.n unicode_data.n	\
	units.n uri.n urn-scheme.n	\
	uuencode.n uuid.n wip.n	\
	xsxp.n	\
	yaml.n yencode.n

MANCOMPRESSED=	no
.endif

.include <bsd.port.pre.mk>

CONFIGURE_ENV+=	ac_cv_path_tclsh="${TCLSH}"

post-patch:
	#
	# Ensure, the detailed output of vendors' self-tests is
	# available in addition to the pretty progress report:
	#
	${REINPLACE_CMD} -e 's,test run,test run -l testlog,' \
		-e 's,$$(libdir)/@PACKAGE@@VERSION@,$$(libdir)/@PACKAGE@,' \
		${WRKSRC}/Makefile.in
	${REINPLACE_CMD} -e 's,exec tclsh,exec ${TCLSH},'	\
		${WRKSRC}/apps/dtplite ${WRKSRC}/apps/page	\
		${WRKSRC}/apps/tcldocstrip ${WRKSRC}/apps/nns	\
		${WRKSRC}/apps/nnsd

RUNTEST=	${SETENV} LANG=C DISPLAY= ${MAKE} -C ${WRKSRC} test
MYID	!=	${ID} -u
.if ${MYID} == 0
RUNTEST:=	${SU_CMD:S/root/-m nobody/} "${RUNTEST}"
pre-build:
	#
	# Preparing to run the tests as `nobody'
	#
	${FIND} ${WRKSRC} -type d -o -name jpeg.test | ${XARGS} ${CHOWN} nobody
.endif

test:
	@if ! ${RUNTEST};	\
	then	\
		${AWK} '$$NF == "FAILED" { echo = 1 }	\
			echo { if ($$NF == "start") echo = 0; else print }'	\
				${WRKSRC}/testlog.log;	\
		${CAT} ${WRKSRC}/testlog.failures;	\
		${UNAME} -a;	\
		${ECHO_MSG} Please, analyze and report the test failures;	\
		${ECHO_MSG} Be sure to use the latest available microversion;	\
		${ECHO_MSG} of TCL-${TCL_VER}, however.;	\
	fi

post-build:	test

.include <bsd.port.post.mk>
