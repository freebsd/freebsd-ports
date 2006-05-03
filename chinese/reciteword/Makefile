# Ports collection makefile for:	reciteword
# Date created:			1 November 2004
# Whom:				hamigua <hamigua@cuc.cn>
#
# $FreeBSD$
#

PORTNAME=	reciteword
PORTVERSION=	0.8.2
PORTREVISION=	2
CATEGORIES=	chinese
MASTER_SITES=	http://reciteword.cosoft.org.cn/reciteword/download/
DISTFILES=	${PORTNAME}-${PORTVERSION}.tar.bz2 \
		${PORTNAME}-books-${PORTVERSION}.tar.bz2 \
		${PORTNAME}-dicts-${PORTVERSION}.tar.bz2
EXTRACT_ONLY=	${PORTNAME}-${PORTVERSION}.tar.bz2 \
		${PORTNAME}-books-${PORTVERSION}.tar.bz2 \
		${PORTNAME}-dicts-${PORTVERSION}.tar.bz2

MAINTAINER=	liu_yinghong@yahoo.com.cn
COMMENT=	Education software to help people to study English

USE_ICONV=	yes
NO_PACKAGE=	bsdtar can not handle utf-8 path name correctly under certain circumstance

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib"
USE_GMAKE=	yes
USE_GCC=	3.4
USE_X_PREFIX=	yes
USE_BZIP2=	yes
USE_GNOME=	gnomehack gnomeprefix libgnomeui

RECITE_DATADIR=	${PREFIX}/share/gnome/${PORTNAME}

post-install:
	((cd ${WRKDIR}; ${TAR} -cf - books) | \
	${TAR} --exclude CVS -xf - -C ${RECITE_DATADIR} ; \
	${MV} ${RECITE_DATADIR}/books ${RECITE_DATADIR}/books.EUC-CN)
	(cd ${WRKDIR}; ${TAR} -cf - dicts) | \
	${TAR} --exclude CVS -xf - -C ${RECITE_DATADIR}
	${SETENV} PKG_PREFIX=${PREFIX} RECITE_DATADIR=${RECITE_DATADIR} ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL
	@${FIND} ${RECITE_DATADIR} -not -type d | \
	${SED} -e 's,^${PREFIX}/,,g' >> ${TMPPLIST}
	@${FIND} ${RECITE_DATADIR} -type d | \
	${SED} -e 's,^${PREFIX}/,@dirrm ,g' | ${SORT} -r >> ${TMPPLIST}

.include <bsd.port.mk>
