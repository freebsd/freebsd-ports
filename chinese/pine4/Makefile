# New ports collection makefile for:	pine
# Date created:		15 July 1998
# Whom:			Tai-hwa Liang <avatar@www.mmlab.cse.yzu.edu.tw>
#
# $FreeBSD$
#

PORTNAME=	pine
PORTVERSION=	4.62
PORTREVISION=	0
CATEGORIES=	chinese mail news
MASTER_SITES=	ftp://ftp.cac.washington.edu/pine/
DISTNAME=	${PORTNAME}${PORTVERSION}

PATCH_SITES=	http://people.FreeBSD.org/~avatar/ports/patches/pine/ \
		ftp://www.mmlab.cse.yzu.edu.tw/pub/collect/patch/pine/
PATCHFILES=	${PORTNAME}${PORTVERSION}.patch.gz

MAINTAINER=	avatar@mmlab.cse.yzu.edu.tw
COMMENT=	A Program for Internet News & Email with Chinese(BIG-5) support

USE_BZIP2=	yes

.if defined(WITH_SSL)
USE_OPENSSL=	yes
EXTRA_OPTS=	SSLDIR=${OPENSSLBASE}
.else
EXTRA_OPTS=	NOSSL SSLTYPE=none
.endif

NO_LATEST_LINK=	yes

MAN1=		pine.1 pico.1 pilot.1

pre-fetch:
.if !defined(BATCH) && !defined(PACKAGE_BUILDING)
	${SH} pkg-install
.endif

post-patch:
	for i in ${WRKSRC}/doc/pine.1 \
		${WRKSRC}/pine/filter.c \
		${WRKSRC}/pine/init.c \
		${WRKSRC}/pine/pine.hlp \
		${WRKSRC}/pine/mailcap.c \
		${WRKSRC}/pine/osdep/os-bsf.h ; do \
		${MV} $$i $$i.sed ; \
		${SED} -e "s:@@PREFIX@@:${PREFIX}:g" \
			$$i.sed >$$i ; \
		${RM} $$i.sed ; \
	done
	for i in ${WRKSRC}/doc/tech-notes.txt \
		${WRKSRC}/doc/tech-notes/*.html ; do \
		${MV} $$i $$i.sed ; \
		${SED} -e "s:/usr/local/lib/:${PREFIX}/etc/:g" \
			$$i.sed >$$i ; \
		${RM} $$i.sed ; \
	done

do-build:
	@(cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ./build bsf ${EXTRA_OPTS})

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/pico ${PREFIX}/bin/pico
	${INSTALL_PROGRAM} ${WRKSRC}/bin/pilot ${PREFIX}/bin/pilot
	${INSTALL_PROGRAM} ${WRKSRC}/bin/pine ${PREFIX}/bin/pine
	${SED} -e 's,@@PREFIX@@,${PREFIX},g' \
		< ${FILESDIR}/pgpdecode > ${WRKSRC}/bin/pgpdecode
	${SED} -e 's,@@PREFIX@@,${PREFIX},g' \
		< ${FILESDIR}/pgpencrypt > ${WRKSRC}/bin/pgpencrypt
	${SED} -e 's,@@PREFIX@@,${PREFIX},g' \
		< ${FILESDIR}/pgpsign > ${WRKSRC}/bin/pgpsign
	${INSTALL_SCRIPT} ${WRKSRC}/bin/pgpencrypt ${PREFIX}/bin/pgpencrypt
	${INSTALL_SCRIPT} ${WRKSRC}/bin/pgpdecode ${PREFIX}/bin/pgpdecode
	${INSTALL_SCRIPT} ${WRKSRC}/bin/pgpsign ${PREFIX}/bin/pgpsign
	${SED} -e 's,@@PREFIX@@,${PREFIX},g' \
		< ${FILESDIR}/dot.pinerc.sample \
		> ${WRKSRC}/dot.pinerc.sample
	${INSTALL_DATA} ${WRKSRC}/dot.pinerc.sample \
			${PREFIX}/etc/dot.pinerc.sample
	${SED} -e 's,@@PREFIX@@,${PREFIX},g' \
		< ${FILESDIR}/dot.pinerc.pgp.sample \
		> ${WRKSRC}/dot.pinerc.pgp.sample
	${INSTALL_DATA} ${WRKSRC}/dot.pinerc.pgp.sample \
			${PREFIX}/etc/dot.pinerc.pgp.sample
	${INSTALL_MAN} ${WRKSRC}/doc/pico.1 ${PREFIX}/man/man1/pico.1
	${INSTALL_MAN} ${WRKSRC}/doc/pilot.1 ${PREFIX}/man/man1/pilot.1
	${INSTALL_MAN} ${WRKSRC}/doc/pine.1 ${PREFIX}/man/man1/pine.1
.if !defined(NOPORTDOCS)
	${INSTALL} -d -o ${SHAREOWN} -g ${SHAREGRP} \
			${PREFIX}/share/doc/pine \
			${PREFIX}/share/doc/pine/tech-notes
	${INSTALL_DATA} ${WRKSRC}/doc/brochure.txt ${PREFIX}/share/doc/pine
	${INSTALL_DATA} ${WRKSRC}/doc/tech-notes.txt ${PREFIX}/share/doc/pine
	${INSTALL_DATA} ${WRKSRC}/doc/tech-notes/*.html \
			${PREFIX}/share/doc/pine/tech-notes/
.endif

post-install:
	${PREFIX}/bin/pine -P ${PREFIX}/etc/pine.conf -conf >${WRKSRC}/pine.conf
	${INSTALL_DATA} ${WRKSRC}/pine.conf ${PREFIX}/etc/pine.conf
	@${ECHO} "	- - - - - - - - - - - - - - - - - - - - - - - - -"
	@${ECHO} "	If Pine exits with \"Received abort signal\" try"
	@${ECHO} "	disabling the \"quell-folder-internal-msg\" feature"
	@${ECHO} "	- - - - - - - - - - - - - - - - - - - - - - - - -"

.include <bsd.port.mk>
