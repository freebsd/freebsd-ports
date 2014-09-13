# Created by: Junho CHOI <junho.choi@gmail.com>
# $FreeBSD$

PORTNAME=	ami
PORTVERSION=	1.2.3
PORTREVISION=	2
CATEGORIES=	korean x11
MASTER_SITES=	http://kldp.net/frs/download.php/942/ \
		http://www.kr.freebsd.org/~hwang/ami/:hjdic \
		ftp://ftp.kr.freebsd.org/pub/FreeBSD-kr/distfiles/:amidic
DISTFILES=	${DISTNAME}.tar.gz hanja.dic.gz:hjdic ami.dic:amidic
EXTRACT_ONLY=	${DISTNAME}.tar.gz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Well-known Korean X11 Input Method

LICENSE=	GPLv2

USES=		iconv gmake
USE_GNOME=	gtk12 gdkpixbuf
GNU_CONFIGURE=	yes

PORTDOCS=	AUTHORS ChangeLog NEWS README README.en

OPTIONS_DEFINE=	DOCS NLS
OPTIONS_SUB=	yes

NLS_CONFIGURE_ENABLE=	nls
NLS_USES=		gettext
NLS_LDFLAGS=	-L${LOCALBASE}/lib
NLS_CPPFLAGS=	-I${LOCALBASE}/include

post-build:
	( cd ${WRKSRC}/hanjadic && ${SETENV} ${MAKE_ENV} ${MAKE} )
	${GUNZIP_CMD} -cd ${DISTDIR}/hanja.dic.gz > ${WRKDIR}/hanja.dic
	${CAT} ${DISTDIR}/ami.dic >> ${WRKDIR}/hanja.dic

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	( cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR} )
	${INSTALL_DATA} ${WRKDIR}/hanja.dic ${STAGEDIR}${DATADIR}

.include <bsd.port.mk>
