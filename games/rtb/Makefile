# New ports collection makefile for:	RealTimeBattle
# Date created:				30 June 2000
# Whom:				Dishanker Rajakulendren <draj@oceanfree.net>
#
# $FreeBSD$
#

PORTNAME=	RealTimeBattle
PORTVERSION=	1.0.8
PORTREVISION=	6
CATEGORIES=	games
MASTER_SITES=	SF${PORTNAME:}
DISTNAME=	${PORTNAME}-${PORTVERSION}-Ext

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Robot programming game for UNIX

BUILD_DEPENDS=	gsed:${PORTSDIR}/textproc/gsed

USE_BZIP2=	yes
USE_GNOME=	gnometarget gtk20
USE_PERL5=	yes
USE_PYTHON=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"
CONFIGURE_ARGS=	--with-rtb-dir=${PREFIX}/lib/${PORTNAME}

CPPFLAGS=	-I${LOCALBASE}/include -DHAVE_DECL_GETOPT
LDFLAGS=	-L${LOCALBASE}/lib

post-patch:
.for file in configure
	@${REINPLACE_CMD} -e '/test/s| == | = |g ; \
		 s|INCLUDED_LIBINTL=yes|INCLUDED_LIBINTL=no|g ; \
		 s|\\$${top_builddir}/intl/libintl.a|-lintl|g' ${WRKSRC}/${file}
.endfor
.for file in Makefile.in
	@${REINPLACE_CMD} -e '/^SUBDIRS/s|Documentation||g' ${WRKSRC}/${file}
.endfor
.for file in team-framework/createrobot.sh \
	team-framework/createrobotconf.sh
	@${REINPLACE_CMD} -e 's| sed| gsed|g' ${WRKSRC}/${file}
.endfor

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for file in AUTHORS ChangeLog EXTRAROBOTS.README NEWS README TODO \
	Documentation/RealTimeBattle-1.html \
	Documentation/RealTimeBattle-2.html \
	Documentation/RealTimeBattle-3.html \
	Documentation/RealTimeBattle-4.html \
	Documentation/RealTimeBattle-5.html \
	Documentation/RealTimeBattle-6.html \
	Documentation/RealTimeBattle.html \
	Documentation/next.gif Documentation/prev.gif Documentation/toc.gif \
	Documentation/next.png Documentation/prev.png Documentation/toc.png \
	Documentation/RealTimeBattle.dvi \
	Documentation/RealTimeBattle.sgml \
	Documentation/RealTimeBattle.txt \
	Documentation/RTB-Team-Framework-Tutorial.tar.gz
	${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
