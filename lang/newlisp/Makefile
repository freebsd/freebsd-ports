# New ports collection makefile for:	newlisp
# Date created:		2006-09-13
# Whom:			Stanislav Sedov <ssedov@mbsd.msk.ru>
#
# $MBSDlabs$
# $FreeBSD$
#

PORTNAME=	newlisp
PORTVERSION=	9.0.0
CATEGORIES=	lang
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=${PORTNAME}
EXTRACT_SUFX=	.tgz

MAINTAINER=	stas@FreeBSD.org
COMMENT=	LISP like scripting language

RUN_DEPENDS=	wish${TK_VER}:${PORTSDIR}/x11-toolkits/tk${TK_VER:S,.,,g}

HAS_CONFIGURE=	yes
ALL_TARGET=	default

TK_VER=	8.4
MAN1=	newlisp.1 newlisp-tk.1

.include <bsd.port.pre.mk>

post-patch:
	@${REINPLACE_CMD} -E -e "s,install -m 644, \$${BSD_INSTALL_DATA},g" \
		-e "s,install -m 755, \$${BSD_INSTALL_SCRIPT},g" \
		-e "s,^(datadir=).*,\1${PREFIX}/share,g" \
		-e "s,^(mandir=).*,\1${PREFIX}/man,g" \
		-e "s,^(bindir=).*,\1${PREFIX}/bin,g" \
		${WRKSRC}/Makefile

	@${REINPLACE_CMD} -E -e "s,exec wish,exec wish${TK_VER}," \
		-e "s,/usr/share/newlisp,${DATADIR},g" \
		-e "s,/usr/bin,${PREFIX}/bin,g" \
		${WRKSRC}/newlisp-tk/newlisp-tk.tcl

.include <bsd.port.post.mk>
