# New ports collection makefile for:    rar
# http://www.inetpros.net/rar.htm
# Version required:     2.01
# Date created:         15 May 1996
# Whom:                 ache
#
# $Id: Makefile,v 1.8 1997/11/26 01:41:36 jseger Exp $
#

DISTNAME=       rarbsd
PKGNAME=        rar-2.01
CATEGORIES=	archivers
MASTER_SITES=	ftp://ftp.kiarchive.ru/pub/unix/arcers/
EXTRACT_SUFX=   .exe

MAINTAINER=     ache@FreeBSD.ORG

NO_PACKAGE=     Only unmodified original package can be distributed

NO_WRKSUBDIR=   yes
EXTRACT_CMD=
EXTRACT_BEFORE_ARGS=

post-fetch:
	chmod a+x ${DISTDIR}/${DISTFILES}

do-build:
	cd ${WRKSRC} && \
		for i in *.Txt *.Lst; do \
			${TR} -d '\015' < $$i > $$i.tmp; \
			${MV} $$i.tmp $$i; \
		done

do-install:
	install -d -m 755 -o ${SHAREOWN} -g ${SHAREGRP} \
		${PREFIX}/share/doc/rar ${PREFIX}/share/rar
	cd ${WRKSRC} && \
		${INSTALL_PROGRAM} RAR ${PREFIX}/bin/rar && \
		${INSTALL_MAN} Rar.Txt ${PREFIX}/man/cat1/rar.1 && \
		${INSTALL_MAN} Rar_FAQ.Txt TechNote.Txt License.Txt Internet.Txt \
			${PREFIX}/share/doc/rar && \
		${INSTALL_DATA} RarFiles.Lst \
			${PREFIX}/share/rar/rarfiles.lst && \
		${INSTALL_DATA} DEFAULT.SFX \
			${PREFIX}/share/rar/default.sfx && \
		${INSTALL_DATA} Dos.SFX \
			${PREFIX}/share/rar/dos.sfx

.include <bsd.port.mk>

.if ${PORTOBJFORMAT} == "elf"
STRIP=
.endif
