# New ports collection makefile for:	qcad
# Date created:		10 Dec 1999
# Whom:			Thomas Gellekum <tg@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	qcad
PORTVERSION=	1.4.7
CATEGORIES=	cad
MASTER_SITES=	http://www.qcad.org/archives/
DISTNAME=	${PORTNAME}-${PORTVERSION}-src

MAINTAINER=	ports@FreeBSD.org

USE_XLIB=	yes
USE_QT_VER=	2
MAKE_ENV=	QTDIR="${X11BASE}"

.include <bsd.port.pre.mk>

.if ${MACHINE_ARCH} == "alpha"
CFLAGS+=	-O0
.endif

post-patch:
	@${PERL} -pi -e "s|%%PREFIX%%|${PREFIX}|g" ${WRKSRC}/*.cpp

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/qcad ${PREFIX}/bin
	@${MKDIR} ${PREFIX}/share/qcad
.for dir in cur fonts hatches libraries messages xpm
	${TAR} -C ${WRKSRC} -cf - ${dir} | \
		${TAR} -C ${PREFIX}/share/qcad --unlink -xf -
.endfor
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/examples/qcad
	${TAR} -C ${WRKSRC}/examples -cf - . | \
		${TAR} -C ${PREFIX}/share/examples/qcad --unlink -xf -
	@${MKDIR} ${PREFIX}/share/doc/qcad
	${TAR} -C ${WRKSRC}/doc -cf - . | \
		${TAR} -C ${PREFIX}/share/doc/qcad --unlink -xf -
	@${LN} -sf ${PREFIX}/share/doc/qcad ${PREFIX}/share/qcad/doc
.endif

.include <bsd.port.post.mk>
