# New ports collection makefile for:	griffith
# Date created:		27 January 2007
# Whom:			Andrew Pantyukhin <infofarmer@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	griffith
PORTVERSION=	0.11
PORTREVISION=	3
CATEGORIES=	deskutils
MASTER_SITES=	http://launchpadlibrarian.net/37682783/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Lightweight film collection manager

RUN_DEPENDS=	py*-pysqlite>=2.0:${PORTSDIR}/databases/py-pysqlite23 \
		py*-sqlalchemy>=0.5:${PORTSDIR}/databases/py-sqlalchemy \
		py*-imaging>=0:${PORTSDIR}/graphics/py-imaging \
		py*-reportlab>=1.19:${PORTSDIR}/print/py-reportlab \
		py*-chardet>=0:${PORTSDIR}/textproc/py-chardet \
		${PYXML}

USE_GNOME=	pygtk2
WANT_GNOME=	yes
USE_PYTHON=	yes
USE_GETTEXT=	yes
USE_GMAKE=	yes
NO_BUILD=	yes

MANLANG=	"" pl pt
MAN1=		${PORTNAME}.1

.include <bsd.port.pre.mk>

.if ${HAVE_GNOME:Mpygnomeextras}!=""
USE_GNOME+=	pygnomeextras
.endif

post-patch:
.for file in Makefile
	@${REINPLACE_CMD} -e \
		'/^LANGUAGES=/s|find.*|cd i18n/\&\&ls -d *)|g ; \
		 /^PREFIX/s|^|#|g ; \
		 /^ETCDIR/s|=.*|= $$(PREFIX)/etc|g' ${WRKSRC}/${file}
.endfor
.for file in docs/en/Makefile docs/pl/Makefile docs/pt/Makefile
	@${REINPLACE_CMD} -e \
		'/^PREFIX/s|^|#|g ; \
		 /^MANDIR/s|=.*|=${MANPREFIX}/man|g' ${WRKSRC}/${file}
.endfor

.include <bsd.port.post.mk>
