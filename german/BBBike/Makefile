# New ports collection makefile for:	BBBike
# Date created:		Fri Aug 14 15:32:26 CEST 1998
# Whom:			Slaven Rezic <eserte@cs.tu-berlin.de>
#
# $FreeBSD$
#

PORTNAME=	BBBike
PORTVERSION=	3.11
CATEGORIES=	german
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	bbbike

MAINTAINER=	slaven.rezic@berlin.de

RUN_DEPENDS=	${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/${PERL_ARCH}/Tk.pm:${PORTSDIR}/x11-toolkits/p5-Tk

USE_PERL5=	YES
POD2MAN=	pod2man

MAN1=		bbbike.1

MYDESTDIR=	${PREFIX}/BBBike

.if !defined(PERL_VER) || ${PERL_VER} == 5.005
PLIST=		${PKGDIR}/pkg-plist.5005
.endif

do-build:
	cd ${WRKSRC}/ext/BBBikeXS; ${PERL5} Makefile.PL; make all install clean; ${RM} Makefile.old
	cd ${WRKSRC}/ext/VirtArray; ${PERL5} Makefile.PL; make all install clean; ${RM} Makefile.old
	cd ${WRKSRC}; ${POD2MAN} --lax bbbike.pod > bbbike.1
	${MV} ${WRKSRC}/bbbike ${WRKSRC}/bbbike.tmp
	${ECHO_CMD} "#! ${PERL}" > ${WRKSRC}/bbbike
	${CAT} ${WRKSRC}/bbbike.tmp >> ${WRKSRC}/bbbike
	${RM} -f ${WRKSRC}/bbbike.tmp
	${CHMOD} 0755 ${WRKSRC}/bbbike

BBBIKEEXE=	bbbike cbbbike bbbikeclient cmdbbbike

do-install:
	-${RM} -rf ${MYDESTDIR}
	${CP} -r  ${WRKSRC} ${MYDESTDIR}
	${FIND} ${MYDESTDIR} -exec ${CHMOD} ugo+r {} \;
	${FIND} ${MYDESTDIR} -perm -u=x -exec ${CHMOD} go+x {} \;
.for f in ${BBBIKEEXE}
	-${RM} -f ${PREFIX}/bin/$f
	${LN} -s  ${MYDESTDIR}/$f ${PREFIX}/bin/$f
.endfor
	${INSTALL_MAN} ${WRKSRC}/bbbike.1 ${PREFIX}/man/man1

.include <bsd.port.mk>
