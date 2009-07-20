# New ports collection makefile for:	ebview
# Date Created:		28 Jan 2002
# Whom:			Yoichi NAKAYAMA <yoichi@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	ebview
PORTVERSION=	0.2.1
PORTREVISION=	9
CATEGORIES=	japanese
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Electronic Book Viewer

LIB_DEPENDS=	eb.14:${PORTSDIR}/japanese/eb

CONFLICTS=	ja-ebview-gtk2-*

USE_GNOME=	imlib
USE_GMAKE=	yes
USE_AUTOTOOLS=	autoconf:262
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"
MAKE_ARGS=	ACLOCAL="${TRUE}" AUTOCONF="${TRUE}" AUTOMAKE="${TRUE}" \
		AUTOHEADER="${TRUE}"

CPPFLAGS=	-I${LOCALBASE}/include
LDFLAGS=	-L${LOCALBASE}/lib

.include <bsd.port.pre.mk>

pre-build:
.for file in src/dictheading.c
	cd ${WRKSRC} && ${MV} ${file} ${file}.pre_iconv \
		&& iconv -c -t ascii ${file}.pre_iconv > ${file} || ${TRUE}
.endfor

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for i in ChangeLog README
	${INSTALL_DATA} ${WRKSRC}/${i} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.post.mk>
