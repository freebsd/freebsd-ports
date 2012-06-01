# New ports collection makefile for:	ami
# Date created:		05 Jun 1999
# Whom:			CHOI Junho <cjh@kr.freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	ami
PORTVERSION=	1.2.3
PORTREVISION=	1
CATEGORIES=	korean x11
MASTER_SITES=	http://kldp.net/frs/download.php/942/ \
		http://www.kr.freebsd.org/~hwang/ami/:hjdic \
		ftp://ftp.kr.freebsd.org/pub/FreeBSD-kr/distfiles/:amidic
DISTFILES=	${DISTNAME}.tar.gz hanja.dic.gz:hjdic ami.dic:amidic
EXTRACT_ONLY=	${DISTNAME}.tar.gz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Well-known Korean X11 Input Method

LICENSE=	GPLv2

USE_ICONV=	yes
USE_GMAKE=	yes
USE_GNOME=	gtk12 gdkpixbuf
WANT_GNOME=	yes
GNU_CONFIGURE=	yes

.if !defined(WITHOUT_NLS)
USE_GETTEXT=	yes
LDFLAGS+=	-L${LOCALBASE}/lib
CPPFLAGS+=	-I${LOCALBASE}/include
PLIST_SUB+=	NLS=""
.else
CONFIGURE_ARGS+=--disable-nls
PLIST_SUB+=	NLS="@comment "
.endif

PORTDOCS=	AUTHORS ChangeLog NEWS README README.en

.include <bsd.port.pre.mk>

post-build:
	( cd ${WRKSRC}/hanjadic && ${SETENV} ${MAKE_ENV} ${MAKE} )
	${GUNZIP_CMD} -cd ${DISTDIR}/hanja.dic.gz > ${WRKDIR}/hanja.dic
	${CAT} ${DISTDIR}/ami.dic >> ${WRKDIR}/hanja.dic

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/ami
	( cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${DOCSDIR} )
.endif
	${INSTALL_DATA} ${WRKDIR}/hanja.dic ${DATADIR}

.include <bsd.port.post.mk>
