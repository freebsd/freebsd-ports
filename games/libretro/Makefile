# $FreeBSD$

PORTNAME=	libretro
PORTVERSION=	0.1
CATEGORIES=	games

MAINTAINER=	menelkir@itroll.org
COMMENT=	Meta-port for libretro cores

USES=		metaport

OPTIONS_DEFINE=		2048 BEETLE_BSNES BEETLE_GBA BEETLE_LYNX BEETLE_NGP \
			BEETLE_PCE_FAST BEETLE_PCFX BEETLE_PSX BEETLE_SUPERGRAFX \
			BEETLE_VB BEETLE_WSWAN BLUEMSX DESMUME2015 DOSBOX EMUX \
			FBALPHA FCEUMM FUSE GAMBATTE GENESIS_PLUS_GX GPSP GW HANDY \
			HATARI MAME2000 MAME2003 MAME2003_PLUS MGBA NESTOPIA NXENGINE \
			O2EM OPERA PCSX_REARMED PICODRIVE PRBOOM PROSYSTEM QUICKNES \
			SCUMMVM SNES9X SNES9X2005 SNES9X2010 STELLA2014 TGBDUAL \
			TYRQUAKE UAE VBANEXT VECX VIRTUALJAGUAR
OPTIONS_DEFAULT=	2048 BEETLE_BSNES BEETLE_GBA BEETLE_LYNX BEETLE_NGP \
			BEETLE_PCE_FAST BEETLE_PCFX BEETLE_PSX BEETLE_SUPERGRAFX \
			BEETLE_VB BEETLE_WSWAN BLUEMSX DESMUME2015 DOSBOX EMUX \
			FBALPHA FCEUMM FUSE GAMBATTE GENESIS_PLUS_GX GPSP GW HANDY \
			HATARI MAME2000 MAME2003 MAME2003_PLUS MGBA NESTOPIA NXENGINE \
			O2EM OPERA PCSX_REARMED PICODRIVE PRBOOM PROSYSTEM QUICKNES \
			SCUMMVM SNES9X SNES9X2005 SNES9X2010 STELLA2014 TGBDUAL \
			TYRQUAKE UAE VBANEXT VECX VIRTUALJAGUAR

OPTIONS_DEFAULT_aarch64=	2048 BEETLE_BSNES BEETLE_GBA BEETLE_LYNX BEETLE_NGP \
			BEETLE_PCE_FAST BEETLE_PCFX BEETLE_PSX BEETLE_SUPERGRAFX \
			BEETLE_VB BEETLE_WSWAN DOSBOX EMUX \
			FBALPHA FCEUMM FUSE GAMBATTE GENESIS_PLUS_GX GPSP GW HANDY \
			HATARI MAME2000 MAME2003 MAME2003_PLUS MGBA NESTOPIA NXENGINE \
			O2EM OPERA PCSX_REARMED PRBOOM PROSYSTEM QUICKNES \
			SCUMMVM SNES9X SNES9X2005 SNES9X2010 STELLA2014 TGBDUAL \
			TYRQUAKE UAE VBANEXT VECX VIRTUALJAGUAR

2048_DESC=			2048 puzzle game
BEETLE_BSNES_DESC=		Mednafen Super Nintendo
BEETLE_GBA_DESC=		Mednafen GameBoy Advance
BEETLE_LYNX_DESC=		Mednafen Atari Lynx
BEETLE_NGP_DESC=		Mednafen SNK Neo Geo Pocket
BEETLE_PCE_FAST_DESC=		Mednafen NEC PC-Engine/Turbografx-16
BEETLE_PCFX_DESC=		Mednafen NEC PC-FX
BEETLE_PSX_DESC=		Mednafen Sony Playstation
BEETLE_SUPERGRAFX_DESC=		Mednafen NEC Supergrafx
BEETLE_VB_DESC=			Mednafen Nintendo Virtual Boy
BEETLE_WSWAN_DESC=		Mednafen Nintendo Bandai Wonderswan
BLUEMSX_DESC=			MSX1/2/Turbo-R
DESMUME2015_DESC=		Nintendo DS
DOSBOX_DESC=			MS-DOS
EMUX_DESC=			Multiple 8-Bit Console (Chip-8, GameBoy, NES, Mastersystem)
FBALPHA_DESC=			Final Burn Alpha
FCEUMM_DESC=			Nintendo NES/Famicon
FUSE_DESC=			Sinclair ZX-Spectrum
GAMBATTE_DESC=			Nintendo GameBoy Color
GENESIS_PLUS_GX_DESC=		Sega 8-bit/16-bit Consoles and peripherals
GPSP_DESC=			Nintendo GameBoy
GW_DESC=			Nintendo Game & Watch
HANDY_DESC=			Atari Lynx
HATARI_DESC=			Atari ST/STE/TT/Falcon
MAME2000_DESC=			M.A.M.E 0.37b5
MAME2003_DESC=			M.A.M.E 0.78
MAME2003_PLUS_DESC=		M.A.M.E 0.78 with extra additions
MGBA_DESC=			Nintendo Gameboy Advance
NESTOPIA_DESC=			Nintendo NES/Famicon
NXENGINE_DESC=			Cave Story game
O2EM_DESC=			Magnavox Odyssey 2 / Philips Videopac
OPERA_DESC=			Panasonic 3DO
PCSX_REARMED_DESC=		Sony Playstation
PICODRIVE_DESC=			Sega Genesis/Megadrive with peripherals
PRBOOM_DESC=			Doom game
PROSYSTEM_DESC=			Atari 7800
QUICKNES_DESC=			Nintendo NES
SCUMMVM_DESC=			Script Creation Utility for Maniac Mansion Virtual Machine
SNES9X_DESC=			Nintendo Super NES/Super Famicon (Trunk)
SNES9X2005_DESC=		Nintendo Super NES/Super Famicon (1.43)
SNES9X2010_DESC=		Nintendo Super NES/Super Famicon (1.52)
STELLA2014_DESC=		Atari 2600
TGBDUAL_DESC=			Nintendo GameBoy and GameBoy Color (with link support)
TYRQUAKE_DESC=			Quake game
UAE_DESC=			Commodore Amiga
VBANEXT_DESC=			Nintendo GameBoy Advance
VECX_DESC=			GCE Vectrex
VIRTUALJAGUAR_DESC=		Atari Jaguar

2048_RUN_DEPENDS=		libretro-2048>=0:games/libretro-2048
BEETLE_BSNES_RUN_DEPENDS=	libretro-beetle_bsnes>=0:games/libretro-beetle_bsnes
BEETLE_GBA_RUN_DEPENDS=		libretro-beetle_gba>=0:games/libretro-beetle_gba
BEETLE_LYNX_RUN_DEPENDS=	libretro-beetle_lynx>=0:games/libretro-beetle_lynx
BEETLE_NGP_RUN_DEPENDS=		libretro-beetle_ngp>=0:games/libretro-beetle_ngp
BEETLE_PCE_FAST_RUN_DEPENDS=	libretro-beetle_pce_fast>=0:games/libretro-beetle_pce_fast
BEETLE_PCFX_RUN_DEPENDS=	libretro-beetle_pcfx>=0:games/libretro-beetle_pcfx
BEETLE_PSX_RUN_DEPENDS=		libretro-beetle_psx>=0:games/libretro-beetle_psx
BEETLE_SUPERGRAFX_RUN_DEPENDS=	libretro-beetle_supergrafx>=0:games/libretro-beetle_supergrafx
BEETLE_VB_RUN_DEPENDS=		libretro-beetle_vb>=0:games/libretro-beetle_vb
BEETLE_WSWAN_RUN_DEPENDS=	libretro-beetle_wswan>=0:games/libretro-beetle_wswan
BLUEMSX_RUN_DEPENDS=		libretro-bluemsx>=0:games/libretro-bluemsx
DESMUME2015_RUN_DEPENDS=	libretro-desmume2015>=0:games/libretro-desmume2015
DOSBOX_RUN_DEPENDS=		libretro-dosbox>=0:games/libretro-dosbox
EMUX_RUN_DEPENDS=		libretro-emux>=0:games/libretro-emux
FBALPHA_RUN_DEPENDS=		libretro-fbalpha>=0:games/libretro-fbalpha
FCEUMM_RUN_DEPENDS=		libretro-fceumm>=0:games/libretro-fceumm
FUSE_RUN_DEPENDS=		libretro-fuse>=0:games/libretro-fuse
GAMBATTE_RUN_DEPENDS=		libretro-gambatte>=0:games/libretro-gambatte
GENESIS_PLUS_GX_RUN_DEPENDS=	libretro-genesis_plus_gx>=0:games/libretro-genesis_plus_gx
GPSP_RUN_DEPENDS=		libretro-gpsp>=0:games/libretro-gpsp
GW_RUN_DEPENDS=			libretro-gw>=0:games/libretro-gw
HANDY_RUN_DEPENDS=		libretro-handy>=0:games/libretro-handy
HATARI_RUN_DEPENDS=		libretro-hatari>=0:games/libretro-hatari
MAME2000_RUN_DEPENDS=		libretro-mame2000>=0:games/libretro-mame2000
MAME2003_RUN_DEPENDS=		libretro-mame2003>=0:games/libretro-mame2003
MAME2003_PLUS_RUN_DEPENDS=	libretro-mame2003_plus>=0:games/libretro-mame2003_plus
MGBA_RUN_DEPENDS=		libretro-mgba>=0:games/libretro-mgba
NESTOPIA_RUN_DEPENDS=		libretro-nestopia>=0:games/libretro-nestopia
NXENGINE_RUN_DEPENDS=		libretro-nxengine>=0:games/libretro-nxengine
O2EM_RUN_DEPENDS=		libretro-o2em>=0:games/libretro-o2em
OPERA_RUN_DEPENDS=		libretro-opera>=0:games/libretro-opera
PCSX_REARMED_RUN_DEPENDS=	libretro-pcsx_rearmed>=0:games/libretro-pcsx_rearmed
PICODRIVE_RUN_DEPENDS=		libretro-picodrive>=0:games/libretro-picodrive
PRBOOM_RUN_DEPENDS=		libretro-prboom>=0:games/libretro-prboom
PROSYSTEM_RUN_DEPENDS=		libretro-prosystem>=0:games/libretro-prosystem
QUICKNES_RUN_DEPENDS=		libretro-quicknes>=0:games/libretro-quicknes
SCUMMVM_RUN_DEPENDS=		libretro-scummvm>=0:games/libretro-scummvm
SNES9X_RUN_DEPENDS=		libretro-snes9x>=0:games/libretro-snes9x
SNES9X2005_RUN_DEPENDS=		libretro-snes9x2005>=0:games/libretro-snes9x2005
SNES9X2010_RUN_DEPENDS=		libretro-snes9x2010>=0:games/libretro-snes9x2010
STELLA2014_RUN_DEPENDS=		libretro-stella2014>=0:games/libretro-stella2014
TGBDUAL_RUN_DEPENDS=		libretro-tgbdual>=0:games/libretro-tgbdual
TYRQUAKE_RUN_DEPENDS=		libretro-tyrquake>=0:games/libretro-tyrquake
UAE_RUN_DEPENDS=		libretro-uae>=0:games/libretro-uae
VBANEXT_RUN_DEPENDS=		libretro-vbanext>=0:games/libretro-vbanext
VECX_RUN_DEPENDS=		libretro-vecx>=0:games/libretro-vecx
VIRTUALJAGUAR_RUN_DEPENDS=	libretro-virtualjaguar>=0:games/libretro-virtualjaguar

.include <bsd.port.mk>
