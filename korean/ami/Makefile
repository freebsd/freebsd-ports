# New ports collection makefile for:	ami
# Date created:		05 Jun 1999
# Whom:			CHOI Junho <cjh@kr.freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	ami
PORTVERSION=	1.0.11
PORTREVISION=	1
CATEGORIES=	korean x11
MASTER_SITES=	http://www.kr.freebsd.org/~hwang/ami/ \
		http://master.debian.or.kr/~cwryu/archive/misc/
DISTFILES=	${DISTNAME}.tar.gz hanja.dic.gz ami.dic
EXTRACT_ONLY=	${DISTNAME}.tar.gz

MAINTAINER=	cjh@FreeBSD.org

LIB_DEPENDS=	gdk_pixbuf.2:${PORTSDIR}/graphics/gdk-pixbuf

USE_X_PREFIX=	yes
USE_GTK=	yes
USE_GMAKE=	yes
WANT_GNOME=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-hangul-keyboard=2 --datadir=${PREFIX}/${DATADIR}
DATADIR=	share

.include <bsd.port.pre.mk>

# gnome support
.if defined(HAVE_GNOME)
USE_GNOME=	yes
USE_GNOMECTRL=	yes
CONFIGURE_ARGS+=--enable-gnome-applet
DATADIR=	share/gnome
CATEGORIES+=	gnome
.endif

pre-everything::
.if !defined(HAVE_GNOME)
	@${ECHO} Define WITH_GNOME=yes if you want to enable GNOME applet support.
.else
	@${ECHO} Define WITHOUT_GNOME=yes if you want to build without GNOME
	@${ECHO} applet support and with minimal dependencies.
.endif

post-build:
	@cd ${WRKSRC}/hanjadic; \
	${MAKE_ENV} ${MAKE} ${MAKE_ARGS}

post-install:
	${INSTALL_PROGRAM} ${WRKSRC}/hanjadic/hanja-hwp2ami ${PREFIX}/bin
	${MKDIR} ${PREFIX}/share/doc/ami
.for NAME in AUTHORS README README.en NEWS ChangeLog
	${INSTALL_DATA} ${WRKSRC}/${NAME} \
		${PREFIX}/share/doc/ami
.endfor
	${GUNZIP_CMD} -cd ${DISTDIR}/hanja.dic.gz > \
			${PREFIX}/${DATADIR}/ami/hanja.dic
	${CAT} ${DISTDIR}/ami.dic >> ${PREFIX}/${DATADIR}/ami/hanja.dic

.include <bsd.port.post.mk>
