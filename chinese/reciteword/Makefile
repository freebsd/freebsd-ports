# Ports collection makefile for:	reciteword
# Date created:			1 November 2004
# Whom:				hamigua <hamigua@cuc.cn>
#
# $FreeBSD$
#

PORTNAME=	reciteword
PORTVERSION=	0.8.3
PORTREVISION=	2
CATEGORIES=	chinese
MASTER_SITES=	http://reciteword.cosoft.org.cn/reciteword/download/ \
		ftp://local-distfiles.freebsd.org.cn/pub/china-ports/hamigua/
DISTFILES=	${PORTNAME}-${PORTVERSION}.tar.bz2 \
		${PORTNAME}-books-${PORTVERSION}.tar.bz2 \
		${PORTNAME}-dicts-0.8.2.tar.bz2
EXTRACT_ONLY=	${PORTNAME}-${PORTVERSION}.tar.bz2 \
		${PORTNAME}-books-${PORTVERSION}.tar.bz2 \
		${PORTNAME}-dicts-0.8.2.tar.bz2

MAINTAINER=	liu_yinghong@yahoo.com.cn
COMMENT=	Education software to help people to study English

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib"
USE_GMAKE=	yes
USE_GCC=	3.4
USE_X_PREFIX=	yes
USE_BZIP2=	yes
USE_GETTEXT=	yes
USE_GNOME=	gtk20 esound

OPTIONS=	RPTTS "With Real People TTS" off

.include <bsd.port.pre.mk>

.if defined(WITH_RPTTS)
RUN_DEPENDS+=	${LOCALBASE}/share/WyabdcRealPeopleTTS/a/a.wav:${PORTSDIR}/textproc/stardict2-rptts
.endif

RECITE_DATADIR=	${PREFIX}/share/${PORTNAME}

post-patch:
	@${REINPLACE_CMD} -e 's|/usr|${LOCALBASE}|' ${WRKSRC}/src/readword.cpp

post-install:
	(cd ${WRKDIR}; ${TAR} -cf - books) | \
	${TAR} --exclude CVS -xf - -C ${RECITE_DATADIR} ; \
	(cd ${WRKDIR}; ${TAR} -cf - dicts) | \
	${TAR} --exclude CVS -xf - -C ${RECITE_DATADIR}

.include <bsd.port.post.mk>
