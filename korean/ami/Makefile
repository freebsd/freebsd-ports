# New ports collection makefile for:	ami
# Date created:		05 Jun 1999
# Whom:			CHOI Junho <cjh@kr.freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	ami
PORTVERSION=	1.2.2
PORTREVISION=	7
CATEGORIES=	korean x11
MASTER_SITES=	http://download.kldp.net/ami/ \
		http://www.kr.freebsd.org/~hwang/ami/:hjdic \
		ftp://ftp.kr.freebsd.org/pub/FreeBSD-kr/distfiles/:amidic
DISTFILES=	${DISTNAME}.tar.gz hanja.dic.gz:hjdic ami.dic:amidic
EXTRACT_ONLY=	${DISTNAME}.tar.gz

MAINTAINER=	cjh@FreeBSD.org
COMMENT=	Well-known Korean X11 Input Method

USE_GETTEXT=	yes
USE_ICONV=	yes
USE_GMAKE=	yes
USE_GNOME=	gtk12 gdkpixbuf
WANT_GNOME=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-hangul-keyboard=2 --datadir=${PREFIX}/${DATADIR} \
		--with-libiconv-prefix=${LOCALBASE} \
		--with-gdk-pixbuf-prefix=${LOCALBASE} \
		--with-libintl-prefix=${LOCALBASE}
DATADIR=	share

.include <bsd.port.pre.mk>

post-build:
	@cd ${WRKSRC}/hanjadic; \
	${MAKE_ENV} ${MAKE} ${MAKE_ARGS}

post-install:
	${MKDIR} ${PREFIX}/share/doc/ami
.for NAME in AUTHORS README README.en NEWS ChangeLog
	${INSTALL_DATA} ${WRKSRC}/${NAME} \
		${PREFIX}/share/doc/ami
.endfor
	${GUNZIP_CMD} -cd ${DISTDIR}/hanja.dic.gz > \
			${PREFIX}/${DATADIR}/ami/hanja.dic
	${CAT} ${DISTDIR}/ami.dic >> ${PREFIX}/${DATADIR}/ami/hanja.dic

.include <bsd.port.post.mk>
