# New ports collection makefile for:  gcin
# Date created:                   Feb 18 2004
# Whom:                           Shen Chuan-Hsing
#
# $FreeBSD$
#

PORTNAME=	gcin
PORTVERSION=	1.0.1
PORTREVISION=	1
CATEGORIES=	chinese
MASTER_SITES=	http://www.csie.nctu.edu.tw/~cp76/gcin/download/ \
		http://edt1023.sayya.org/gcin/source/ \
		http://edt1023.sayya.org/misc/ \
		http://bbs.ilc.edu.tw/~chinsan/gcin/
.if defined(WITH_BOSHIAMY)
DISTFILES=	${GCINFILE} ${BOSHIAMYFILE}
EXTRACT_ONLY=	${GCINFILE}
.endif

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A traditional chinese input utility in X

USE_X_PREFIX=	YES
USE_BZIP2=	YES
GNU_CONFIGURE=	YES
USE_GNOME=	gtk20
USE_GMAKE=	YES

MAN1=		gcin.1 gcin2tab.1

.include <bsd.port.pre.mk>

pre-everything::
	@${ECHO_MSG} ''
	@${ECHO_MSG} 'gcin has the following tunable option:'
	@${ECHO_MSG} '    WITH_BOSHIAMY  - enable Boshiamy support'
	@${ECHO_MSG} ''
	@${ECHO_MSG} 'Example:  "make WITH_BOSHIAMY=yes install clean" '
	@${ECHO_MSG} ''

.if ${OSVERSION} <= 500034
USE_GCC=	3.4
.endif

.if defined(WITH_BOSHIAMY)
IGNOREFILES=	${BOSHIAMYFILE}
GCINFILE=	${PORTNAME}-${PORTVERSION}${EXTRACT_SUFX}
BOSHIAMYFILE=	noseeing.tar.gz
post-extract:
	@cd ${WRKSRC}/data/ \
		&& ${TAR} -zxf ${DISTDIR}/${BOSHIAMYFILE} \
		&& ${RM} -f noseeing.gtab
post-patch:
EXTRA_PATCHES+=	${FILESDIR}/extra-patch-data-Makefile
PLIST_SUB+=	BOSHIAMY=""
.else
PLIST_SUB+=	BOSHIAMY="@comment "
.endif

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for file in Changelog README
	${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
.endif
	@gtk-query-immodules-2.0 > ${PREFIX}/etc/gtk-2.0/gtk.immodules
	@${CAT} ${PKGMESSAGE}
	@${ECHO} To display this message again, type \`pkg_info -D ${PKGNAME}\'

.include <bsd.port.post.mk>
