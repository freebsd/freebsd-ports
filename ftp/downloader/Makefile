# ex:ts=8
# New ports collection makefile for:	downloader
# Date Created:		23 June 1999
# Whom:			Ying-Chieh Liao <ijliao@csie.nctu.edu.tw>
#
# $FreeBSD$
#

PORTNAME=	downloader
PORTVERSION=	2.0
CATEGORIES=	ftp
MASTER_SITES=	http://www.krasu.ru/soft/chuchelo/files/ \
		ftp://ftp.chg.ru/pub/X11/applications/Xdownloader/ \
		http://www.scutty.co.uk/downloader/software/ \
		ftp://ftp.uni-klu.ac.at/pub/linux/internet/downloader/
DISTNAME=	d4x-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org

LIB_DEPENDS=	gdk_pixbuf:${PORTSDIR}/graphics/gdk-pixbuf \
		intl.2:${PORTSDIR}/devel/gettext \
		iconv.3:${PORTSDIR}/converters/libiconv

USE_BISON=	yes
USE_GLIB=	yes
USE_GTK=	yes
USE_ESOUND=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="${CXXFLAGS} -I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
CONFIGURE_ARGS=	--mandir=${PREFIX}/man
USE_GMAKE=	yes

MAN1=		nt.1

post-patch:
	@${PERL} -pi -e "s,Bison ,Bison,g ; \
		s,-lpthread,${PTHREAD_LIBS},g" ${WRKSRC}/configure
	@${PERL} -pi -e 's,-not,\\!,g' ${WRKSRC}/share/Makefile.in

.include <bsd.port.mk>
