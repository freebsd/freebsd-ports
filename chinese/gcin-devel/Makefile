# New ports collection makefile for:  gcin
# Date created:                   Feb 18 2004
# Whom:                           Shen Chuan-Hsing
#
# $FreeBSD$
#

PORTNAME=	gcin
PORTVERSION=	0.9.6
CATEGORIES=	chinese
MASTER_SITES=	http://www.csie.nctu.edu.tw/~cp76/gcin/download/ \
		http://edt1023.sayya.org/misc/
.if defined(WITH_BOSHIAMY)
DISTFILES=	${GCINFILE} ${BOSHIAMYFILE}
EXTRACT_ONLY=	${GCINFILE}
.endif

MAINTAINER=	statue@freebsd.netlab.cse.yzu.edu.tw
COMMENT=	A traditional chinese input utility in X

USE_X_PREFIX=	YES
USE_BZIP2=	YES
GNU_CONFIGURE=	YES
USE_GNOME=	gtk20
USE_GMAKE=	YES
PLIST_SUB+=	BOSHIAMY="@comment "

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
GCINFILE=	${PORTNAME}-${PORTVERSION}${EXTRACT_SUFX}
BOSHIAMYFILE=	noseeing-${BOSHIAMYVER}.tar.gz
BOSHIAMYVER=	3
post-extract:
	@cd ${WRKSRC}/data/ \
		&& ${TAR} -zxf ${DISTDIR}/${BOSHIAMYFILE}
post-patch:
EXTRA_PATCHES+=	${FILESDIR}/extra-patch-data-Makefile
PLIST_SUB+=	BOSHIAMY=""
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
