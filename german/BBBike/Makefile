# Created by: Slaven Rezic <eserte@cs.tu-berlin.de>
# $FreeBSD$

PORTNAME=	BBBike
PORTVERSION=	3.18
PORTREVISION=	4
CATEGORIES=	german
MASTER_SITES=	SF/${PORTNAME:tl}/${PORTNAME}/${PORTVERSION}

MAINTAINER=	slaven@rezic.de
COMMENT=	Route-finder for cyclists in Berlin and Brandenburg

BUILD_DEPENDS=	p5-Inline-C>=0:devel/p5-Inline-C \
		p5-CDB_File>=0:databases/p5-CDB_File
RUN_DEPENDS=	p5-Tk>=0:x11-toolkits/p5-Tk \
		p5-Inline-C>=0:devel/p5-Inline-C \
		p5-CDB_File>=0:databases/p5-CDB_File

USES=		perl5 shebangfix
perl_OLD_CMD=	/usr/perl5.8.0/bin/perl5.8.0 perl
SHEBANG_FILES=	ESRI/Makefile.PL \
		ESRI/esri2bbd.pl \
		ESRI/t/shapefile.t \
		GIS/globe_to_bbd.pl \
		Makefile.PL \
		bbbikeapplet \
		cgi/*.cgi \
		cgi/bbbike.psgi \
		cgi/httpi \
		cgi/mksymlinks \
		cgi/runbbbikecgi \
		ext/BBBikeXS/Makefile.PL \
		ext/BBBikeXS/t/*.t \
		ext/Strassen-Inline/Makefile.PL \
		ext/Strassen-Inline/t/*.t \
		ext/Strassen-Inline/t/common.pl \
		ext/Strassen-Inline2/Makefile.PL \
		ext/Strassen-Inline2/t/*.t \
		ext/Strassen-Inline2/t/common.pl \
		ext/StrassenNetz-CNetFile/Makefile.PL \
		ext/StrassenNetz-CNetFile/t/base.t \
		ext/VectorUtil-Inline/Makefile.PL \
		ext/VectorUtil-Inline/t/*.t \
		ext/VirtArray/Makefile.PL \
		lib/parse_wetterkarte \
		miscsrc/*.pl \
		tkbikepwr
POD2MAN=	pod2man

MYDESTDIR=	${STAGEDIR}${PREFIX}/BBBike

.include <bsd.port.pre.mk>

# The following != assignment will generate a warning
# with portlint et al. Problem is that the nearest
# replacements ${PERL_VER}/${PERL_ARCH} do not work here:
# the value of PERL_ARCH is always "mach" on FreeBSD systems,
# but $Config{archname} here is something like "amd64-freebsd"
.if exists(${PERL5})
LOCAL_PERL_ARCH!=	${PERL5} -MConfig -e '$$x = qq{$$Config{version}/$$Config{archname}}; $$x =~ s{/}{\\\\/}g; print $$x'
.endif
PLIST_SUB=		LOCAL_PERL_ARCH=${LOCAL_PERL_ARCH}
BBBIKE_PERL_EXE=	bbbike cbbbike bbbikeclient cmdbbbike smsbbbike

post-patch:
	@${RM} ${WRKSRC}/tmp/.keep_me

do-build:
	cd ${WRKSRC}/ext && ${MAKE} PERL=${PERL} all install
	cd ${WRKSRC}/ext && ${MAKE} PERL=${PERL} clean
	${FIND} ${WRKSRC}/lib -name "*.so" | ${XARGS} ${CHMOD} u+w
	${FIND} ${WRKSRC}/lib -name "*.so" | ${XARGS} ${STRIP_CMD}
	${FIND} ${WRKSRC}/lib -name "*.so" | ${XARGS} ${CHMOD} u-w
	cd ${WRKSRC}; ${POD2MAN} --lax bbbike.pod > bbbike.1
.for f in ${BBBIKE_PERL_EXE}
	${MV} ${WRKSRC}/$f ${WRKSRC}/$f.tmp
	${ECHO_CMD} "#! ${PERL}" > ${WRKSRC}/$f
	${CAT} ${WRKSRC}/$f.tmp >> ${WRKSRC}/$f
	${RM} -f ${WRKSRC}/$f.tmp
	${CHMOD} 0755 ${WRKSRC}/$f
.endfor

do-install:
	-${RM} -rf ${MYDESTDIR}
	${INSTALL_MAN} ${WRKSRC}/bbbike.1 ${STAGEDIR}${PREFIX}/man/man1
	${FIND} ${WRKSRC} | ${XARGS} ${CHMOD} ugo+r
	${FIND} ${WRKSRC} -perm -u=x | ${XARGS} ${CHMOD} go+x
	${CP} -rp ${WRKSRC} ${MYDESTDIR}
	${RM} -f ${MYDESTDIR}/bbbike.1
.for f in ${BBBIKE_PERL_EXE}
	-${RM} -f ${STAGEDIR}${PREFIX}/bin/$f
	${LN} -s  ../BBBike/$f ${STAGEDIR}${PREFIX}/bin/$f
.endfor

.include <bsd.port.post.mk>
