# New ports collection makefile for: VJE-Delta Ver 2.5 [FREE TRIAL VERSION]
# Version required:	2.5
# Date created:		17 April 1998
# Whom:			sada
#
# $Id: Makefile,v 1.1.1.1 1998/08/25 22:06:49 kuriyama Exp $
#

DISTNAME=	vje
PKGNAME=	ja-vje-2.5t
CATEGORIES=	japanese
MASTER_SITES=	http://www.green.machida.ne.jp/vacs/unix/FreeBSD/ \
		ftp://ftp.vacs.co.jp/pub/unix/FreeBSD/
EXTRACT_SUFX=	.tgz

MAINTAINER=	sada@e-mail.ne.jp

DIST_SUBDIR=	${PKGNAME}
NO_BUILD=	yes
RESTRICTED=	Redistribution is forbidden

INSTALL_DIR=	${PREFIX}/vje
DOC_DIR=	${PREFIX}/share/doc/${PKGNAME}
SAMPLE_DIR=	${PREFIX}/share/examples/${PKGNAME}
MAKESCRIPT=     ${SED} -e "s;@PREFIX@;${PREFIX};g"
CHMOD=		/bin/chmod
INVOKE=		${SETENV} PKG_PREFIX=${PREFIX} ${SH}

.SILENT:

do-configure:
	${MAKESCRIPT} ${FILESDIR}/vjed.sh.in >${WRKSRC}/vjed.sh
do-install:
	${MKDIR} ${PREFIX}/libexec
	${INSTALL_PROGRAM} ${WRKSRC}/bin/vjed ${PREFIX}/libexec
	${MKDIR} ${PREFIX}/bin
.for i in vadd vdel vdispd vje vjekill vmaked vpen vpr vprc vpu
	${INSTALL_PROGRAM} ${WRKSRC}/bin/$i ${PREFIX}/bin
.endfor
	${MKDIR} ${INSTALL_DIR}/dic
.for i in vjed95m.dic vjed95u.dic
	${INSTALL_DATA} ${WRKSRC}/dic/$i ${INSTALL_DIR}/dic
.endfor
	${CHMOD} a+w ${INSTALL_DIR}/dic/vjed95?.dic
	${MKDIR} ${PREFIX}/etc/rc.d
	${INSTALL_SCRIPT} ${WRKSRC}/vjed.sh ${PREFIX}/etc/rc.d
	${MKDIR} ${DOC_DIR}
	${INSTALL_DATA} ${FILESDIR}/readme.freebsd ${DOC_DIR}
.for i in FAQ readme
	${INSTALL_DATA} ${WRKSRC}/$i.euc ${DOC_DIR}/$i
.endfor
.for i in delta deltabug dictools pen penbug sample
	${INSTALL_DATA} ${WRKSRC}/doc/$i.euc ${DOC_DIR}/$i
.endfor
	${MKDIR} ${SAMPLE_DIR}
.for i in vje.conf vje.rom
	${INSTALL_DATA} ${WRKSRC}/$i ${SAMPLE_DIR}
.endfor
.for i in atok-ux.env atok-ux.rom canna.env canna.rom vje-ux.env vje-ux.rom \
		wnn.env wnn.rom
	${CP} ${WRKSRC}/sample/$i ${SAMPLE_DIR}
	${CHMOD} a+w ${SAMPLE_DIR}/$i
.endfor
	${INVOKE} ${PKGDIR}/INSTALL ${PKGNAME} POST-INSTALL

.include <bsd.port.mk>
