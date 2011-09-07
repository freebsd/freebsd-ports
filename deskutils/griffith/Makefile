# New ports collection makefile for:	griffith
# Date created:		27 January 2007
# Whom:			Andrew Pantyukhin <infofarmer@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	griffith
PORTVERSION=	0.12.1
PORTREVISION=	2
CATEGORIES=	deskutils
MASTER_SITES=	http://launchpadlibrarian.net/58153655/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Lightweight film collection manager

LICENSE=	GPLv2 GPLv3
LICENSE_COMB=	dual

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}sqlite3>=0:${PORTSDIR}/databases/py-sqlite3 \
		${PYTHON_PKGNAMEPREFIX}sqlalchemy06>=0.5:${PORTSDIR}/databases/py-sqlalchemy06 \
		${PYTHON_PKGNAMEPREFIX}imaging>=0:${PORTSDIR}/graphics/py-imaging \
		${PYTHON_PKGNAMEPREFIX}reportlab>=1.19:${PORTSDIR}/print/py-reportlab \
		${PYTHON_PKGNAMEPREFIX}chardet>=0:${PORTSDIR}/textproc/py-chardet \
		${PYXML}

USE_XZ=		yes
USE_GNOME=	pygtk2
WANT_GNOME=	yes
USE_PYTHON=	2.5+
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
