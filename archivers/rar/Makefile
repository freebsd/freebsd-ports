# New ports collection makefile for:    rar
# Date created:         15 May 1996
# Whom:                 ache
#
# $FreeBSD$
#

PORTNAME=	rar
PORTVERSION=	2.02
CATEGORIES=	archivers
MASTER_SITES=	ftp://rarsoft.ti.sk/pub/rar/ \
		ftp://ftp.cdrom.com/pub/sac/pack/
DISTNAME=	rarbsd
EXTRACT_SUFX=	.sfx

MAINTAINER=	ache@FreeBSD.org

CAT1=		rar.1

ONLY_FOR_ARCHS=	i386
NO_PACKAGE=	Only unmodified original package can be distributed
NO_BUILD=	yes
NO_WRKSUBDIR=	yes
EXTRACT_CMD=		# empty
EXTRACT_BEFORE_ARGS=	# empty
EXTRACT_AFTER_ARGS=	# empty

.include <bsd.port.pre.mk>

.if ${PORTOBJFORMAT} == "elf"
STRIP=
.endif

post-fetch:
	@${CHMOD} a+x ${DISTDIR}/${DISTFILES}

do-install:
	${MKDIR} ${PREFIX}/share/doc/rar ${PREFIX}/share/rar
	${INSTALL_PROGRAM} ${WRKSRC}/rar ${PREFIX}/bin/rar
	cd ${WRKSRC} && \
		${INSTALL_MAN} Rar.Txt ${PREFIX}/man/cat1/rar.1 && \
		${INSTALL_DATA} Rar_FAQ.txt TechNote.Txt License.Txt \
			       Internet.Txt \
			${PREFIX}/share/doc/rar && \
		${INSTALL_DATA} RarFiles.Lst \
			${PREFIX}/share/rar/rarfiles.lst && \
		${INSTALL_DATA} default.sfx \
			${PREFIX}/share/rar && \
		${INSTALL_DATA} Dos.SFX \
			${PREFIX}/share/rar/dos.sfx

.include <bsd.port.post.mk>
