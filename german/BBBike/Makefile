# Created by: Slaven Rezic <eserte@cs.tu-berlin.de>
# $FreeBSD$

PORTNAME=	BBBike
PORTVERSION=	3.18
PORTREVISION=	1
CATEGORIES=	german
MASTER_SITES=	SF/${PORTNAME:L}/${PORTNAME}/${PORTVERSION}

MAINTAINER=	slaven@rezic.de
COMMENT=	A route-finder for cyclists in Berlin and Brandenburg

BUILD_DEPENDS=	p5-Inline>=0:${PORTSDIR}/devel/p5-Inline \
		p5-CDB_File>=0:${PORTSDIR}/databases/p5-CDB_File
RUN_DEPENDS=	p5-Tk>=0:${PORTSDIR}/x11-toolkits/p5-Tk \
		${BUILD_DEPENDS}

USE_PERL5=	YES
POD2MAN=	pod2man

MAN1=		bbbike.1

MYDESTDIR=	${PREFIX}/BBBike

LOCAL_PERL_ARCH=	${PERL_ARCH}
PLIST_SUB=		LOCAL_PERL_ARCH=${LOCAL_PERL_ARCH}

do-build:
	cd ${WRKSRC}/ext && ${MAKE} PERL=${PERL5} all install
	cd ${WRKSRC}/ext && ${MAKE} PERL=${PERL5} clean
	cd ${WRKSRC}; ${POD2MAN} --lax bbbike.pod > bbbike.1
	${MV} ${WRKSRC}/bbbike ${WRKSRC}/bbbike.tmp
	${ECHO_CMD} "#! ${PERL}" > ${WRKSRC}/bbbike
	${CAT} ${WRKSRC}/bbbike.tmp >> ${WRKSRC}/bbbike
	${RM} -f ${WRKSRC}/bbbike.tmp
	${CHMOD} 0755 ${WRKSRC}/bbbike

BBBIKEEXE=	bbbike cbbbike bbbikeclient cmdbbbike smsbbbike
PLIST_IN=	${PKGDIR}/pkg-plist.in
PLIST=		${WRKDIR}/pkg-plist

pre-install:
	LOCAL_PERL_ARCH=`${PERL5} -MConfig -e '$$x = qq{$$Config{version}/$$Config{archname}}; $$x =~ s{/}{\\\\/}g; print $$x'`; \
	${SED} -e "s/%%LOCAL_PERL_ARCH%%/$$LOCAL_PERL_ARCH/g" < ${PLIST_IN} > ${PLIST}

do-install:
	-${RM} -rf ${MYDESTDIR}
	${INSTALL_MAN} ${WRKSRC}/bbbike.1 ${PREFIX}/man/man1
	${CP} -r ${WRKSRC} ${MYDESTDIR}
	${RM} -f ${MYDESTDIR}/bbbike.1
	${FIND} ${MYDESTDIR} | ${XARGS} ${CHMOD} ugo+r
	${FIND} ${MYDESTDIR} -perm -u=x | ${XARGS} ${CHMOD} go+x
.for f in ${BBBIKEEXE}
	-${RM} -f ${PREFIX}/bin/$f
	${LN} -s  ${MYDESTDIR}/$f ${PREFIX}/bin/$f
.endfor

.include <bsd.port.mk>
