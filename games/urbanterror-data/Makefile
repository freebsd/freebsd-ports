# Created by: alepulver
# $FreeBSD$

PORTNAME=	data
PORTVERSION=	4.2.023
CATEGORIES=	games
MASTER_SITES=	http://cdn.urbanterror.info/urt/42/zips/ \
		http://www.f1m.fr/uploads/urt/ \
		http://mirror.urtstats.net/urbanterror/
PKGNAMEPREFIX=	urbanterror-
DISTNAME=	UrbanTerror${URT_VER}_full${URT_REV}
EXTRACT_SUFX=	.zip
EXTRACT_ONLY=

MAINTAINER=	kami@FreeBSD.org
COMMENT=	Standalone realism based mod originally for Quake III Arena

NO_BUILD=	yes
NO_CDROM=	The mod files may not be sold or distributed on physical media unless with permission from id Software.

DATADIR=	${PREFIX}/share/quake3
DOCSDIR=	${PREFIX}/share/doc/${PKGNAMEPREFIX}${PORTNAME}

URT_VER=	${PORTVERSION:C/([0-9]+).([0-9]+).*/\1\2/}
URT_REV=	${PORTVERSION:C/([0-9]+\.[0-9]+).*\.([0-9]+)/\2/}

PLIST_SUB+=	VER=${URT_VER}

BROKEN_aarch64=		Fails to install: runaway process
BROKEN_armv6=		Fails to install: runaway process
BROKEN_mips=		Fails to install: runaway process
BROKEN_mips64=		Fails to install: runaway process

OPTIONS_DEFINE=	DOCS
OPTIONS_SUB=	yes

UTDOCS=		readme${URT_VER}.txt \
		How_To_Install.txt \
		QIIIA_Game_Source_License.doc

.include <bsd.port.options.mk>

do-install:
	${MKDIR} ${STAGEDIR}${DATADIR}/q3ut4
	${TAR} ${EXTRACT_BEFORE_ARGS} ${DISTDIR}/${DISTFILES} \
		${EXTRACT_AFTER_ARGS} -C ${STAGEDIR}${DATADIR} --strip-components 1 \
		UrbanTerror${URT_VER}/q3ut4
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${MV} ${UTDOCS:C!^!${STAGEDIR}${DATADIR}/q3ut4/!} ${STAGEDIR}${DOCSDIR}/
.else
	${RM} ${UTDOCS:C!^!${STAGEDIR}${DATADIR}/q3ut4/!}
.endif

.include <bsd.port.mk>
