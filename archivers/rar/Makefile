# New ports collection makefile for:    rar
# http://www.rarsoft.com/
# Version required:     2.*
# Date created:         15 May 1996
# Whom:                 ache
#
# $FreeBSD$
#

DISTNAME=       rarbsd
PKGNAME=        rar-2.02
CATEGORIES=	archivers
MASTER_SITES=   ftp://ftp.rarsoft.com/pub/rar/ \
		ftp://ftp.cdrom.com/pub/sac/pack/
EXTRACT_SUFX=   .sfx

MAINTAINER=     ache@FreeBSD.ORG

ONLY_FOR_ARCHS=	i386
NO_PACKAGE=     Only unmodified original package can be distributed
NO_BUILD=       yes
NO_WRKSUBDIR=   yes
EXTRACT_CMD=		# empty
EXTRACT_BEFORE_ARGS=	# empty
EXTRACT_AFTER_ARGS=	# empty

.include <bsd.port.pre.mk>

.if ${PORTOBJFORMAT} == "elf"
STRIP=
.endif

post-fetch:
	@${CHMOD} a+x ${DISTDIR}/${DISTFILES}

#do-build:
#        cd ${WRKSRC} && \
#                for i in *.Txt *.Lst; do \
#                        ${TR} -d '\015' < $$i > $$i.tmp; \
#                        ${MV} $$i.tmp $$i; \
#                done

do-install:
	$(INSTALL) -d -m 755 -o ${SHAREOWN} -g ${SHAREGRP} \
		${PREFIX}/share/doc/rar ${PREFIX}/share/rar
	cd ${WRKSRC} && \
		${INSTALL_PROGRAM} rar ${PREFIX}/bin/rar && \
		${INSTALL_MAN} Rar.Txt ${PREFIX}/man/cat1/rar.1 && \
		${INSTALL_MAN} Rar_FAQ.txt TechNote.Txt License.Txt \
			       Internet.Txt \
			${PREFIX}/share/doc/rar && \
		${INSTALL_DATA} RarFiles.Lst \
			${PREFIX}/share/rar/rarfiles.lst && \
		${INSTALL_DATA} default.sfx \
			${PREFIX}/share/rar && \
		${INSTALL_DATA} Dos.SFX \
			${PREFIX}/share/rar/dos.sfx

.include <bsd.port.post.mk>
