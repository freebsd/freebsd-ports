# New ports collection makefile for:	alliance
# Date created:		6 May 2004
# Whom:			hrs
#
# $FreeBSD$

PORTNAME=	alliance
PORTVERSION=	5.0.20031209
CATEGORIES=	cad
MASTER_SITES=	http://www-asim.lip6.fr/pub/alliance/distribution/5.0/ \
		${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	hrs
DISTNAME=	${PORTNAME}-5.0-20031209

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	A complete set of CAD tools and libraries for VLSI design

WRKSRC=		${WRKDIR}/${PORTNAME}-5.0

USE_BISON=	yes
USE_GMAKE=	yes
USE_MOTIF=	yes
USE_REINPLACE=	yes
USE_X=		yes

HAS_CONFIGURE=	yes
CONFIGURE_ENV+=	ALLIANCE_TOP=${ALLIANCE_TOP}
CONFIGURE_ARGS+=--mandir=${PREFIX}/man \
		--x-libraries=${X11BASE}/lib \
		--x-includes=${X11BASE}/include \
		--prefix=${ALLIANCE_TOP} ${CONFIGURE_TARGET}

PKGMESSAGE=	${WRKDIR}/pkg-message
PKGMESSAGE_IN=	${FILESDIR}/pkg-message.in

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 502126
BROKEN=		"Does not compile on FreeBSD >= 5.x"
.endif

ALLIANCE_TOP=	${PREFIX}/alliance
SRCDIRLIST!=	${CAT} ${FILESDIR}/srcdirs.list
CFLAGS+=	${SRCDIRLIST:S,^,-I${WRKSRC}/,}
LDFLAGS+=	${SRCDIRLIST:S,^,-L${WRKSRC}/,}
CONFIGURE_ENV+=	CFLAGS="${CFLAGS}" CPPFLAGS="${CFLAGS}" LDFLAGS="${LDFLAGS}"
MAKE_ENV+=	CFLAGS="${CFLAGS}" CPPFLAGS="${CFLAGS}" LDFLAGS="${LDFLAGS}"

MAN1=	MBK_CATAL_NAME.1 MBK_CATA_LIB.1 MBK_FILTER_SFX.1 \
	MBK_IN_FILTER.1 MBK_IN_LO.1 MBK_IN_PH.1 MBK_OUT_FILTER.1 \
	MBK_OUT_LO.1 MBK_OUT_PH.1 MBK_SEPAR.1 MBK_TRACE_GETENV.1 \
	MBK_VDD.1 MBK_VSS.1 MBK_CK.1 MBK_WORK_LIB.1 \
	aut.1 abl.1 bdd.1 log.1 fsm.1 druc.1 alcbanner.1 \
	asimut.1 attila.1 boog.1 boom.1 alc_bug_report.1 \
	alc_origin.1 dreal.1 exp.1 flatbeh.1 flatlo.1 flatph.1 \
	fmi.1 fsp.1 genlib.1 genpat.1 graal.1 k2f.1 l2p.1 loon.1 \
	lvx.1 cougar.1 m2e.1 moka.1 nero.1 ocp.1 proof.1 ring.1 \
	s2r.1 scapin.1 syf.1 vasy.1 x2y.1 xpat.1 xsch.1

MAN3=	addcapa.3 addchain.3 addhtitem.3 addlocon.3 addlofig.3 \
	addloins.3 addlomodel.3 addlosig.3 addlotrs.3 addlocap.3 \
	addlores.3 addloself.3 addnum.3 addphcon.3 addphfig.3 \
	addphins.3 addphref.3 addphseg.3 addphvia.3 addptype.3 \
	getlocap.3 getlores.3 getloself.3 setlocap.3 setlores.3 \
	setloself.3 alliancebanner.3 append.3 bigvia.3 chain.3 \
	checkloconorder.3 concatname.3 defab.3 delchain.3 delht.3 \
	delhtitem.3 dellocon.3 dellofig.3 delloins.3 dellosig.3 \
	dellotrs.3 dellocap.3 dellores.3 delloself.3 delnum.3 \
	delphcon.3 delphfig.3 delphins.3 delphref.3 delphseg.3 \
	delphvia.3 delptype.3 downstr.3 filepath.3 flattenlofig.3 \
	flattenphfig.3 freechain.3 freelomodel.3 freenum.3 freeptype.3 \
	gethtitem.3 getlocon.3 getlofig.3 getloins.3 getlomodel.3 \
	getlosig.3 getphcon.3 getphfig.3 getphins.3 getphref.3 getptype.3 \
	getsigname.3 mbksetautoackchld.3 givelosig.3 guessextdir.3 \
	incatalog.3 incatalogdelete.3 incatalogfeed.3 incataloggds.3 \
	instanceface.3 instr.3 isvdd.3 isvss.3 isck.3 loadlofig.3 \
	loadphfig.3 locon.3 lofig.3 lofigchain.3 log.3 loins.3 losig.3 \
	lotrs.3 locap.3 lores.3 loself.3 mbk.3 mbkalloc.3 mbkenv.3 \
	mbkps.3 mbkfopen.3 mbkfree.3 mbkgetenv.3 mbkrealloc.3 mbkunlink.3 \
	mbkwaitpid.3 mlodebug.3 mphdebug.3 namealloc.3 namefind.3 \
	nameindex.3 naturalstrcmp.3 phcon.3 phfig.3 phins.3 phref.3 \
	phseg.3 phvia.3 ptype.3 restorealldir.3 restoredirvbe.3 reverse.3 \
	rflattenlofig.3 rflattenphfig.3 autresizeblock.3 savelofig.3 \
	savephfig.3 sethtitem.3 sortlocon.3 sortlosig.3 unflattenlofig.3 \
	upstr.3 viewht.3 viewlo.3 viewlofig.3 viewlofigcon.3 viewloins.3 \
	viewloinscon.3 viewlosig.3 viewlotrs.3 viewlocap.3 viewlores.3 \
	viewloself.3 viewph.3 viewphcon.3 viewphfig.3 viewphins.3 \
	viewphref.3 viewphseg.3 beh.3 viewphvia.3 xyflat.3 autallocblock.3 \
	autfreeheap.3 authelem.3 autallocheap.3 auth2elem.3 authtable.3 \
	autfreeblock.3 auth2table.3 addrdsfig.3 addrdsfigrec.3 \
	addrdsins.3 addrdsinsrec.3 addrdsrecwindow.3 allocrdsfig.3 \
	allocrdsins.3 allocrdsrec.3 allocrdsrecwin.3 allocrdswin.3 \
	conmbkrds.3 modelmbkrds.3 allocrdswindow.3 allocrdswinrec.3 \
	buildrdswindow.3 delrdsfig.3 delrdsfigrec.3 delrdsins.3 \
	delrdsinsrec.3 delrdsrecwindow.3 destroyrdswindow.3 \
	figmbkrds.3 freerdsfig.3 freerdsins.3 freerdsrec.3 \
	getrdsmodellist.3 insconmbkrds.3 insmbkrds.3 insrefmbkrds.3 \
	inssegmbkrds.3 insviambkrds.3 loadrdsfig.3 loadrdsparam.3 \
	rdsalloc.3 rdsenv.3 rdsfree.3 refmbkrds.3 roundrdsrec.3 \
	saverdsfig.3 searchrdsfig.3 segmbkrds.3 viambkrds.3 \
	viewrdsfig.3 viewrdsins.3 viewrdsparam.3 viewrdsrec.3 \
	viewrdswindow.3 viewrfmcon.3 viewrfmfig.3 viewrfmins.3 \
	viewrfmrec.3 viewrfmref.3 viewrfmseg.3 viewrfmvia.3 addablhexpr.3 \
	getablexprlength.3 mapablexpr.3 addablqexpr.3 getablexprmax.3 \
	mapabloperexpr.3 createablatom.3 getablexprmin.3 polarablexpr.3 \
	createablbinexpr.3 getablexprnum.3 polardupablexpr.3 \
	createablnotexpr.3 getablexprnumatom.3 simpablexpr.3 \
	createabloper.3 getablexprnumbinoper.3 simpdupablexpr.3 \
	createablunaryexpr.3 getablexprnumocc.3 substablexpr.3 \
	createablxorbinexpr.3 getablexprsupport.3 substdupablexpr.3 \
	delablexpr.3 isablbinaryoper.3 unflatablexpr.3 delablexprnum.3 \
	isablequalexpr.3 vhdlablname.3 devablxorexpr.3 isablnameinexpr.3 \
	vhdlablvector.3 devdupablxorexpr.3 isabloperinexpr.3 viewablexpr.3 \
	dupablexpr.3 isablsimilarexpr.3 beh_delbeout.3 ARRAY.3 \
	viewablexprfile.3 flatablexpr.3 isablunaryoper.3 viewablexprstr.3 \
	freeablexpr.3 mapablanyexpr.3 getablexprdepth.3 mapableveryexpr.3 \
	addbddassoc.3 addbddcircuitabl.3 addbddcircuitin.3 \
	addbddcircuitout.3 addbddnode.3 addbddnodeassoc.3 addbddnodelist.3 \
	addbddvar.3 addbddvarafter.3 addbddvarbefore.3 addbddvarfirst.3 \
	addbddvarlast.3 applybddnode.3 applybddnodeite.3 applybddnodelist.3 \
	applybddnodenot.3 applybddnodeterm.3 clearbddsystemref.3 \
	clearbddsystemrefext.3 clearbddsystemrefint.3 cofactorbddnode.3 \
	composebddnode.3 convertbddcircuitabl.3 convertbddcircuitsumabl.3 \
	convertbddindexabl.3 convertbddmuxabl.3 convertbddnodeabl.3 \
	convertbddnodesumabl.3 addht.3 createbddcircuit.3 createbddsystem.3 \
	decbddrefext.3 decbddrefint.3 delbddassoc.3 delbddcircuitout.3 \
	delbddnode.3 delbddnodeassoc.3 delbddnodelist.3 destroybddassoc.3 \
	destroybddcircuit.3 destroybddsystem.3 existbddnodeassocoff.3 \
	existbddnodeassocon.3 garbagebddsystem.3 getbddnodenum.3 \
	getbddnodesize.3 getbddnodesupport.3 resetBdd.3 \
	getbddvarbyindex.3 getbddvarindex.3 getbddvarnode.3 \
	getbddvarnodebyindex.3 implybddnode.3 incbddrefext.3 \
	incbddrefint.3 intersectbddnode.3 isbddvarinsupport.3 \
	markbddnode.3 relprodbddnodeassoc.3 reorderbddsystemdynamic.3 \
	reorderbddsystemsimple.3 reorderbddsystemtop.3 \
	reorderbddsystemwindow.3 resetbddcircuit.3 resetbddsystem.3 \
	markBdd.3 restrictbddnode.3 satisfybddnode.3 searchbddcircuitin.3 \
	searchbddcircuitout.3 setbddrefext.3 simpbddnodedcoff.3 \
	simpbddnodedcon.3 substbddnodeassoc.3 swapbddvar.3 \
	testbddcircuit.3 unmarkbddnode.3 unsetbddrefext.3 \
	viewbddcircuit.3 viewbddnode.3 viewbddsystem.3 \
	viewbddsysteminfo.3 composeBdd.3 initializeBdd.3 \
	ablToBddCct.3 constraintBdd.3 markAllBdd.3 simplifDcOneBdd.3 \
	addListBdd.3 createNodeTermBdd.3 simplifDcZeroBdd.3 \
	applyBdd.3 destroyBdd.3 notBdd.3 supportChain_listBdd.3 \
	applyBinBdd.3 displayBdd.3 numberNodeAllBdd.3 upVarBdd.3 \
	bddToAblCct.3 gcNodeBdd.3 numberNodeBdd.3 libpat.3 \
	beh_addbiabl.3 beh_delbereg.3 beh_frebemsg.3 beh_rmvbeaux.3 \
	beh_addbeaux.3 beh_addbinod.3 beh_delberin.3 beh_frebeout.3 \
	beh_rmvbebus.3 beh_addbebus.3 beh_debug.3 beh_delbiabl.3 \
	beh_frebepor.3 beh_rmvbebux.3 beh_addbebux.3 beh_delbeaux.3 \
	beh_delbinod.3 beh_frebereg.3 beh_rmvbefig.3 beh_addbefig.3 \
	beh_delbebus.3 beh_depend.3 beh_freberin.3 beh_rmvbegen.3 \
	beh_addbegen.3 beh_delbebux.3 beh_error.3 beh_frebiabl.3 \
	beh_rmvbemsg.3 beh_addbemsg.3 beh_delbefig.3 beh_frebeaux.3 \
	beh_frebinod.3 beh_rmvbeout.3 beh_addbeout.3 beh_delbegen.3 \
	beh_frebebus.3 beh_getgenva.3 beh_rmvbepor.3 beh_addbepor.3 \
	beh_delbemsg.3 beh_frebebux.3 beh_makbdd.3 beh_rmvbereg.3 \
	beh_addbereg.3 beh_frebefig.3 beh_makgex.3 beh_rmvberin.3 \
	beh_addberin.3 beh_delbepor.3 beh_frebegen.3 beh_message.3 \
	GENLIB_BUS.3 GENLIB_COPY_UP_ALL_CON.3 GENLIB_COPY_UP_ALL_REF.3 \
	GENLIB_COPY_UP_CON.3 GENLIB_COPY_UP_CON_FACE.3 GENLIB_COPY_UP_REF.3 \
	GENLIB_COPY_UP_SEG.3 GENLIB_DEF_AB.3 GENLIB_DEF_LOFIG.3 \
	GENLIB_DEF_PHFIG.3 GENLIB_DEF_PHINS.3 GENLIB_DEF_PHSC.3 \
	GENLIB_ELM.3 GENLIB_FLATTEN_ALL_LOINS.3 GENLIB_FLATTEN_ALL_PHINS.3 \
	GENLIB_FLATTEN_LOFIG.3 GENLIB_FLATTEN_PHFIG.3 GENLIB_GET_CON_X.3 \
	GENLIB_GET_CON_Y.3 GENLIB_GET_INS_X.3 GENLIB_GET_INS_Y.3 \
	GENLIB_GET_REF_X.3 GENLIB_GET_REF_Y.3 GENLIB_HEIGHT.3 \
	GENLIB_LOAD_LOFIG.3 GENLIB_LOAD_PHFIG.3 GENLIB_LOCON.3 \
	GENLIB_LOINS.3 GENLIB_LOINSE.3 GENLIB_LOSIG.3 GENLIB_LOSIGMERGE.3 \
	GENLIB_LOTRS.3 GENLIB_LOCAP.3 GENLIB_LORES.3 GENLIB_LOSELF.3 \
	GENLIB_SET_LOCAP.3 GENLIB_SET_LORES.3 GENLIB_SET_LOSELF.3 \
	GENLIB_OUTLINE.3 GENLIB_PHCON.3 GENLIB_PHREF.3 GENLIB_PHSEG.3 \
	GENLIB_PHVIA.3 GENLIB_PLACE.3 GENLIB_PLACE_BOTTOM.3 \
	GENLIB_PLACE_CON_REF.3 GENLIB_PLACE_LEFT.3 GENLIB_PLACE_ON.3 \
	GENLIB_PLACE_RIGHT.3 GENLIB_PLACE_SEG_REF.3 GENLIB_PLACE_TOP.3 \
	GENLIB_PLACE_VIA_REF.3 GENLIB_REVERSE_PHCON.3 GENLIB_SAVE_LOFIG.3 \
	GENLIB_SAVE_PHFIG.3 GENLIB_SAVE_PHSC.3 GENLIB_SC_BOTTOM.3 \
	GENLIB_SC_LEFT.3 GENLIB_SC_PLACE.3 GENLIB_SC_RIGHT.3 \
	GENLIB_SC_TOP.3 GENLIB_UNFLATTEN_LOFIG.3 GENLIB_WIRE1.3 \
	GENLIB_WIRE2.3 GENLIB_WIRE3.3 GENLIB_MACRO.3 DPGEN_ADSB2F.3 \
	DPGEN_AND2.3 DPGEN_AND3.3 DPGEN_AND4.3 DPGEN_BUFF.3 DPGEN_BUSE.3 \
	DPGEN_CONST.3 DPGEN_DFF.3 DPGEN_DFFT.3 DPGEN_INV.3 DPGEN_MUX2.3 \
	DPGEN_NAND2.3 DPGEN_NAND2MASK.3 DPGEN_NAND3.3 DPGEN_NAND4.3 \
	DPGEN_NBUSE.3 DPGEN_NMUX2.3 DPGEN_NOR2.3 DPGEN_NOR2MASK.3 \
	DPGEN_NOR3.3 DPGEN_NOR4.3 DPGEN_NUL.3 DPGEN_OR2.3 DPGEN_OR3.3 \
	DPGEN_OR4.3 DPGEN_RF1.3 DPGEN_RF1D.3 DPGEN_ROM2.3 DPGEN_ROM4.3 \
	DPGEN_SFF.3 DPGEN_SFFT.3 DPGEN_SHIFT.3 DPGEN_XNOR2.3 \
	DPGEN_XNOR2MASK.3 DPGEN_XOR2.3 AFFECT.3 DECLAR.3 DEF_GENPAT.3 \
	GETCPAT.3 INIT.3 LABEL.3 SAVE.3

MAN5=	ap.5 catal.5 prol.5 vbe.5 vhdl.5 vst.5 al.5 spi.5 ctl.5 \
	fsm.5 pat.5 lax.5 sxlib.5 vasy.5

pre-configure:
	@CONFIG_GUESS_DIRS=$$(${FIND} ${WRKDIR} -name config.guess -o -name config.sub \
		| ${XARGS} -n 1 ${DIRNAME}); \
	for _D in $${CONFIG_GUESS_DIRS}; do \
		${CP} -f ${TEMPLATES}/config.guess $${_D}/config.guess; \
		${CHMOD} a+rx $${_D}/config.guess; \
	    ${CP} -f ${TEMPLATES}/config.sub $${_D}/config.sub; \
		${CHMOD} a+rx $${_D}/config.sub; \
	done

pre-install:
	${MKDIR} ${ALLIANCE_TOP}

post-install:
	@${SED} -e 's,%%PREFIX%%,${PREFIX},' < ${PKGMESSAGE_IN} > ${PKGMESSAGE}
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
