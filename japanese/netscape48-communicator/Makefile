# New ports collection makefile for: Netscape browser with Japanese resources
# Version required:	4.04
# Date created:		13 Mar 1998
# Whom:			sada
#
# $Id: Makefile,v 1.3 1998/03/21 05:04:53 itojun Exp $
#

DISTNAME=	ja-netscape4
CATEGORIES=	japanese www

.if !defined(NAVIGATOR)
MASTER_SITES=	ftp://ftp.netscape.com/pub/communicator/4.04/development/english/unix/freebsd/professional_edition/
DISTFILE=	communicator-v404-export.x86-unknown-freebsd.tar.gz
BROWSER=	communicator
.else
MASTER_SITES=   ftp://ftp.netscape.com/pub/communicator/4.04/development/english/unix/freebsd/navigator_standalone/
DISTFILE=	navigator-v404-export.x86-unknown-freebsd.tar.gz
BROWSER=	navigator
.endif
.if !defined(ENGLISH)
RESOURCE_BASE=	Netscape-jp-v404
MSG_LANG=
.else
RESOURCE_BASE=	Netscape-us-v404
MSG_LANG=		-us
.endif
RUN_DEPENDS=	${X11BASE}/lib/X11/k12:${PORTSDIR}/japanese/k12 \
		${X11BASE}/lib/X11/fonts/misc/5x10B.pcf.Z:${PORTSDIR}/japanese/k10

MANUAL_PACKAGE_BUILD=	have to set ENGLISH and NAGIVATOR variables

DISTFILES=	${DISTFILE}
EXTRACT_ONLY=	${DISTFILE}
MASTER_SITES+=	http://www.bpel.tutics.tut.ac.jp/~take/Netscape/etc/ \
		ftp://ftp.bres.tsukuba.ac.jp/pub/misc/netscape/
RESOURCE_POSTFIX=	19971218.ad
RESOURCE_NAME=	${RESOURCE_BASE}.${RESOURCE_POSTFIX}
DISTFILES+=	NLS.tar.gz ${RESOURCE_NAME}.gz
PKGNAME=	ja-${BROWSER}${MSG_LANG}-4.04
PLIST=		${PKGDIR}/PLIST.${PKGNAME}
MD5_FILE=	${FILESDIR}/md5.${PKGNAME}
EXSRC=		${WRKSRC}/examples/${PKGNAME}
EXDIST=		${PREFIX}/share/examples/${PKGNAME}
EXFILES=	patch.XLC_LOCALE
DOCDIST=	${PREFIX}/share/doc/${PKGNAME}
DOCFILES=	setup.doc

MAINTAINER=	sada@E-mail.NE.JP

NO_WRKSUBDIR=	Yes
NO_BUILD=	Yes
STRIP=

NDIR=		${PREFIX}/lib/${PKGNAME}
BINDIR=		${PREFIX}/bin
NLSDIR=		${NDIR}/nls
RESSUB=		ja_JP.EUC
RESDIR=		${NDIR}/${RESSUB}
LOCDIR=		${NDIR}/locale

.SILENT:

pre-fetch:
.if !defined(NAVIGATOR)
	@${ECHO_MSG} "NOTE: You can install navigator (not communicator) by \"make NAVIGATOR=yes install\"."
.endif
.if !defined(ENGLISH)
	@${ECHO_MSG} "NOTE: You can install English-menu version by \"make ENGLISH=yes install\"."
.endif

post-extract:
	${EXTRACT_CMD} ${EXTRACT_BEFORE_ARGS} ${DISTDIR}/NLS.tar.gz -C ${WRKDIR}
	${CAT} ${DISTDIR}/${RESOURCE_NAME}.gz \
		| ${GUNZIP_CMD} > ${WRKDIR}/${RESOURCE_BASE}.ad

MAKESCRIPT=	${SED} -e "s;@X11BASE@;${X11BASE};g" \
			-e "s;@PREFIX@;${PREFIX};g" \
			-e "s;@NDIR@;${NDIR};g"

do-configure:
#	${MAKESCRIPT} ${FILESDIR}/netscape.sh > ${WRKSRC}/netscape.sh
	${MAKESCRIPT} ${FILESDIR}/ja-netscape.sh > ${WRKSRC}/ja-netscape.sh
	${ECHO} -n 'Communicator,4.04.0.97330,' > ${WRKSRC}/infile
	${ECHO} ${NDIR} >> ${WRKSRC}/infile
#
	${MAKESCRIPT} ${FILESDIR}/setup.pl >${WRKSRC}/setup.pl
	${MKDIR} ${EXSRC}
	for i in ${EXFILES}; do \
		${MAKESCRIPT} ${FILESDIR}/$${i} >${EXSRC}/$${i}; \
	done

do-install:
	${MKDIR} ${NDIR}/java/classes
	${INSTALL_DATA} ${WRKSRC}/*.jar ${NDIR}/java/classes
	${INSTALL_PROGRAM} ${WRKSRC}/vreg ${NDIR}
	for i in ${WRKSRC}/*.nif; do \
		${EXTRACT_CMD} ${EXTRACT_BEFORE_ARGS} $${i} -C ${NDIR}; \
	done
	${INSTALL_DATA} ${FILESDIR}/mailcap ${NDIR}
	${RM} -rf ${NDIR}/movemail-src
	${WRKSRC}/vreg ${NDIR}/registry ${WRKSRC}/infile
	/usr/sbin/chown -R bin:bin ${NDIR}
	${INSTALL_SCRIPT} ${WRKSRC}/ja-netscape.sh ${BINDIR}/${PKGNAME}
	/bin/ln -sf ${PKGNAME} ${BINDIR}/netscape
#
	${MKDIR} ${NLSDIR}/local_im_tbl
	${INSTALL_DATA} ${WRKDIR}/nls/*.*  ${NLSDIR}
	${INSTALL_DATA} ${WRKDIR}/nls/C  ${NLSDIR}
	${RM} -f ${NLSDIR}/*.orig
	${INSTALL_DATA} ${WRKDIR}/nls/local_im_tbl/* ${NLSDIR}/local_im_tbl
	${MKDIR} ${RESDIR}
	${INSTALL_DATA} ${WRKDIR}/${RESOURCE_BASE}.ad ${RESDIR}/Netscape
	${MKDIR} ${LOCDIR}
	/bin/ln -sf /usr/share/locale/en_US.ISO_8859-1 ${LOCDIR}/ja_JP.EUC
	${INSTALL_SCRIPT} ${WRKSRC}/setup.pl ${NDIR}
	${NDIR}/setup.pl install
#
	${MKDIR} ${EXDIST}
	for i in ${EXFILES}; do \
		${INSTALL_SCRIPT} ${EXSRC}/$${i} ${EXDIST}; \
	done
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCDIST}
	${INSTALL_DATA} ${FILESDIR}/setup.doc ${DOCDIST}
.endif
#

plist:
	${ECHO} bin/${PKGNAME} > ${PLIST}
	${ECHO} @exec /bin/ln -sf %f %B/netscape >> ${PLIST}
	${ECHO} @exec /bin/mkdir -p %D/lib/${PKGNAME}/locale >> ${PLIST}
	${ECHO} @exec /bin/ln -sf /usr/share/locale/en_US.ISO_8859-1 %D/lib/${PKGNAME}/locale/ja_JP.EUC >> ${PLIST}
	${ECHO} @unexec /bin/rm -f %D/lib/${PKGNAME}/locale/ja_JP.EUC >> ${PLIST}
	mkplist lib/${PKGNAME} >> ${PLIST}
	mkplist share/examples/${PKGNAME} >> ${PLIST}
	mkplist share/doc/${PKGNAME} >> ${PLIST}
#

post-install:
	@${CAT} ${PKGDIR}/MESSAGE

.include <bsd.port.mk>
