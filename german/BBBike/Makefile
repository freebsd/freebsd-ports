# New ports collection makefile for:	BBBike
# Date created:		Fri Aug 14 15:32:26 CEST 1998
# Whom:			Slaven Rezic <eserte@cs.tu-berlin.de>
#
# $FreeBSD$
#

PORTNAME=	BBBike
PORTVERSION=	3.14
CATEGORIES=	german
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	bbbike

MAINTAINER=	slaven@rezic.de
COMMENT=	A route-finder for cyclists in Berlin and Brandenburg

BUILD_DEPENDS=	${SITE_PERL}/Inline.pm:${PORTSDIR}/devel/p5-Inline \
		${SITE_PERL}/${PERL_ARCH}/CDB_File.pm:${PORTSDIR}/databases/p5-CDB_File
RUN_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/Tk.pm:${PORTSDIR}/x11-toolkits/p5-Tk \
		${BUILD_DEPENDS}

USE_PERL5=	YES
POD2MAN=	pod2man

MAN1=		bbbike.1

MYDESTDIR=	${PREFIX}/BBBike

.if !defined(PERL_VER) || ${PERL_VER} == 5.005
LOCAL_PERL_ARCH=	${PERL_ARCH}
.else
LOCAL_PERL_ARCH=	${PERL_VER}/${ARCH}-freebsd
.endif
PLIST_SUB=		LOCAL_PERL_ARCH=${LOCAL_PERL_ARCH}

.include <bsd.port.pre.mk>

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
PLIST_IN=	pkg-plist.in
PLIST=		${WRKDIR}/pkg-plist

pre-install:
.if !defined(PERL_VER) || ${PERL_VER} == 5.005
	LOCAL_PERL_ARCH=`${PERL5} -MConfig -e 'print "$$Config{archname}"'`; \
	${SED} -e "s|%%LOCAL_PERL_ARCH%%|$$LOCAL_PERL_ARCH|g" < ${PLIST_IN} > ${PLIST}
.else
	LOCAL_PERL_ARCH=`${PERL5} -MConfig -e 'print "$$Config{version}/$$Config{archname}"'`; \
	${SED} -e "s|%%LOCAL_PERL_ARCH%%|$$LOCAL_PERL_ARCH|g" < ${PLIST_IN} > ${PLIST}
.endif

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

.include <bsd.port.post.mk>
