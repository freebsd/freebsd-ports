*** win/jtp/jtp_sdl.c.orig      Sat Feb  8 17:23:47 2003
--- win/jtp/jtp_sdl.c   Sat Feb  8 17:32:00 2003
***************
*** 130,136 ****
--- 130,139 ----
    if (sig_id == SIGCHLD)
    {
      if (jtp_sdl_music_player_pid > 0)
+     {
        kill(jtp_sdl_music_player_pid, SIGKILL);
+       waitpid(jtp_sdl_music_player_pid, NULL, 0);
+     }
      jtp_sdl_music_player_pid = -1;
    }
  }
